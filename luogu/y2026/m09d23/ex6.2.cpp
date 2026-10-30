#include <stdio.h>

#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;

#define MAXSIZE 100

typedef struct {          // 三元组结点结构
    int i, j;             // 非零元素的行、列下标
    ElemType v;           // 非零元素值
} Triple;

typedef struct {          // 稀疏矩阵类型定义
    Triple data[MAXSIZE+1];
    int mu, nu, tu;       // 矩阵的行、列、非零元个数
} Tripletable;

/* （1）稀疏矩阵三元组的插入运算 */
Status InsertTriple(Tripletable &M, int i, int j, ElemType v)
{   // 将一个三元组(i, j, v)插入到稀疏矩阵三元组 M 中，插入后的 M 按行、列有序
    int k;
    if(i<1||j<1||M.tu>=MAXSIZE) return ERROR;    // M.data 的 0 下标不用
    for(k=M.tu; k>0; k--)    // 从 M.tu 到插入点之间的三元组逆序依次向后移动一个位置
        if(M.data[k].i>i||(M.data[k].i==i&&M.data[k].j>j))
        {
            M.data[k+1].i=M.data[k].i;
            M.data[k+1].j=M.data[k].j;
            M.data[k+1].v=M.data[k].v;
        }
        else
            break;
    M.data[k+1].i=i; M.data[k+1].j=j; M.data[k+1].v=v;    // 插入
    M.tu++;    // 调整参数
    return OK;
}

/* （2）创建稀疏矩阵三元组 */
void CreatTriple(Tripletable &M)
{
    int i, j, v, k, tu;
    do {
        printf(" 输入稀疏矩阵的(行数，列数，非零元总数)=>");
        scanf("%d,%d,%d", &M.mu, &M.nu, &tu);
    } while(M.mu<1||M.nu<1||tu<0);
    M.tu=0;
    for(k=1; k<=tu; k++)
    {
        do {
            printf(" 输入第%d 个非零元素的(行≥1,列≥1,值≠0)=>", k);
            scanf("%d,%d,%d",&i, &j, &v);
        } while(i<1|| j<1||v==0);
        InsertTriple(M, i, j, v);    // 调用插入算法创建稀疏矩阵三元组
    }
}

/* （3）输出稀疏矩阵三元组 */
void PrintTriple( Tripletable M)
{
    int ia;
    printf("%4d%4d%4d\n", M.mu, M.nu, M.tu);
    printf("===============\n");
    for(ia=1; ia<=M.tu; ia++)
        printf("%4d%4d%4d\n", M.data[ia].i, M.data[ia].j, M.data[ia].v);
}

/* （4）两个稀疏矩阵相加 */
Status TripleAdd(Tripletable MA, Tripletable MB, Tripletable &MC)
{
    if(MA.tu + MB.tu > MAXSIZE)    // 溢出判断 (1)
        return ERROR;
    int ia=1, ib=1, ic=1, k, temp;
    while(ia<=MA.tu && ib<=MB.tu)
    {
        if( MA.data[ia].i<MB.data[ib].i || (MA.data[ia].i==MB.data[ib].i &&
            MA.data[ia].j<MB.data[ib].j))    // 若 MA 中元素的下标(i, j)更小，
        {    // 则将 MA 中的该元素复制到 MC 中
            MC.data[ic].i=MA.data[ia].i;
            MC.data[ic].j=MA.data[ia].j;
            MC.data[ic++].v=MA.data[ia++].v;
        }
        else if(MA.data[ia].i==MB.data[ib].i && MA.data[ia].j==MB.data[ib].j)
        {    // 若 MA 与 MB 中元素的下标(i, j)相等，则值相加
            temp= MA.data[ia].v+MB.data[ib].v;
            if(temp!=0)
            {
                MC.data[ic].i=MA.data[ia].i;
                MC.data[ic].j=MA.data[ia++].j;
                MC.data[ic++].v=temp;
            }
            else {    // 若两个元素值相加结果得 0，则 MA、MB 同时取下一个元素
                ia++;   // (2)
                ib++;   // (3)
            }
        }
        else    // 否则，MB 的下标更小，取 MB 中的元素到 MC
        {
            MC.data[ic].i=MB.data[ib].i;
            MC.data[ic].j=MB.data[ib].j;
            MC.data[ic++].v=MB.data[ib++].v;
        }
    }
    for(k=ia; k<=MA.tu; k++)    // 将 MA 中剩余的三元组复制到 MC 的尾部
    {
        MC.data[ic].i=MA.data[k].i;
        MC.data[ic].j=MA.data[k].j;
        MC.data[ic++].v=MA.data[k].v;
    }
    for(k=ib; k<=MB.tu; k++)    // 将 MB 中剩余的三元组复制到 MC 的尾部
    {
        MC.data[ic].i=MB.data[k].i;
        MC.data[ic].j=MB.data[k].j;
        MC.data[ic++].v=MB.data[k].v;
    }
    MC.mu=MA.mu;    // 确定 MC 的行、列数及非零元总数
    MC.nu=MA.nu;
    MC.tu= ic - 1;    // (4)
    return OK;
}

/* （5）两个稀疏矩阵相乘 */
int TripleValue(Tripletable M, int i, int j){    // 在 M 中取(i, j)下标对应的元素值
    int k;
    for(k=1; k<=M.tu; k++)
        if(M.data[k].i==i&&M.data[k].j==j )    //若下标 i, j 与第 k 个三元组的 i, j 对应相等
            return (M.data[k].v);               //则返回该三元组的元素值，否则返回 0
    return 0;
}

Status TripleMul (Tripletable A, Tripletable B, Tripletable &C)    // C＝A×B
{
    int i, j, k, p=1, s;    // p 用于统计 C 的非零元个数
    if(A.nu != B.mu) return ERROR;    // 矩阵相乘应满足的条件  (5)
    for(i=0; i<A.mu; i++){
        for(j=0; j<B.nu; j++){
            s=0;
            for(k=0; k<A.nu; k++){
                s=s+TripleValue(A, i, k)*TripleValue(B, k, j);    // 计算 c_i,j
            }
            if(s!=0){
                C.data[p].i=i;
                C.data[p].j=j;
                C.data[p].v=s;
                p++;
            }
        }
    }
    C.mu= A.mu;    // 确定 C 矩阵的行、列数及非零元总数 (6)
    C.nu= B.nu; // (7)
    C.tu=p-1;
    return OK;
}

/* （6）求转置矩阵 */
void TranMat(Tripletable &AT, Tripletable A)
{
    int col, p, q, num[MAXSIZE], cpot[MAXSIZE];
    AT.mu=A.nu; AT.nu=A.mu; AT.tu=A.tu;
    for(col=1; col<=A.nu; col++) num[col]=0;
    for(p=1; p<=A.tu; ++p)    //计算 A 中每列非零元的个数
        num[A.data[p].j]++;   // (8)
    cpot[1]=1;
    for(col=2; col<=A.nu; col++)    //计算转置后元素的位置
        cpot[col]=cpot[col-1]+num[col-1];
    for(p=1; p <= A.tu ; ++p)    //转置   (9)
    {
        col=A.data[p].j; q=cpot[col];
        AT.data[q].i=A.data[p].j;
        AT.data[q].j=A.data[p].i;
        AT.data[q].v=A.data[p].v;
        cpot[col]++;
    }
}

/* 5．主函数设计 */
int main()
{
    Tripletable A, B, C, AT;
    printf("(1) 创建稀疏矩阵 A 的三元组：\n");
    CreatTriple(A);
    printf("A 的三元组输出：\n");
    PrintTriple(A);

    printf("(2) 创建稀疏矩阵 B 的三元组：\n");
    CreatTriple(B);
    printf("B 的三元组输出：\n");
    PrintTriple(B);

    printf("(3) 求 C=A+B。");
    if(A.mu==B.mu && A.nu==B.nu )
    {
        TripleAdd( A, B, C);
        printf("C 的三元组输出：\n");
        PrintTriple(C);
    }
    else printf("A、B 不能相加！\n");

    printf("(4) 求 C=A×B。");
    if( A.nu==B.mu )
    {
        TripleMul(A, B, C);
        printf("C 的三元组输出：\n");
        PrintTriple(C);
    }
    else printf("A、B 不能相乘！\n");

    printf("(5) 求 A 的转置矩阵 AT。AT 的三元组输出：\n");
    TranMat(AT, A);
    PrintTriple(AT);
    return 0;
}