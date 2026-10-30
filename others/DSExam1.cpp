#include <iostream>
using namespace std;

#define MAXSIZE 100 //空间初始分配量
#define LISTINCREMENT 10 //空间分配增量
#define ElemType int
#define OK 1
#define ERROR 0
#define Status int

typedef struct {
    ElemType *elem; //存储空间基址
    int length; //当前长度
    int listsize; //当前分配的存储容量
}SqList;

void Merge(ElemType* help, SqList& L, int l, int m, int r) {
    int i = l, lp = l, rp = m + 1;
    while (lp <= m && rp <= r) {
        if (L.elem[lp] <= L.elem[rp]) help[i++] = L.elem[lp++];
        else help[i++] = L.elem[rp++];
    }
    while (lp <= m) help[i++] = L.elem[lp++];
    while (rp <= r) help[i++] = L.elem[rp++];
    for (int j = l; j <= r; j++) L.elem[j] = help[j];
}

void Sort(ElemType* help, SqList& L, int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    Sort(help, L, l, m);
    Sort(help, L, m + 1, r);
    Merge(help, L, l, m, r);
}

Status CreatSqList(SqList& L) {
    if (!(L.elem = new ElemType[MAXSIZE])) return ERROR;
    L.listsize = MAXSIZE;
    ElemType* help; if (!(help = new ElemType[L.listsize])) return ERROR;
    cout << "请输入" << L.length << "个元素:"; 
    for (int i = 0; i < L.length; i++) cin >> L.elem[i];
    Sort(help, L, 0, L.length - 1);
    return OK;
}   

Status MergeSort(SqList A, SqList B, SqList &C)
// 将两个升序排列的顺序表 A、B 归并到顺序表 C 中，使 C 升序排列
{
    C.elem=(ElemType *)malloc((A.listsize+B.listsize)*sizeof(ElemType));
    if(!C.elem) return ERROR;
    C.listsize=A.listsize+B.listsize;
    int ia = 0, ib = 0, ic = 0;
    while(ia<A.length&&ib<B.length)
    { // 反复取 A、B 表中的小者加入到 C 表，直至其中一个表取完为止
        if(A.elem[ia]<B.elem[ib])
            C.elem[ic++]=A.elem[ia++];
        else if(A.elem[ia]>B.elem[ib])
            C.elem[ic++]=B.elem[ib++];
        else { //两者相等，只取其一
            C.elem[ic++]=A.elem[ia++]; ib++;
        }
    }
    for(int j=ia; j<A.length; j++) // 将 A 表剩余元素复制到 C 表末尾
        C.elem[ic++]=A.elem[j];
    for(int j=ib; j<B.length; j++) // 将 B 表剩余元素复制到 C 表末尾
        C.elem[ic++]=B.elem[j];
    C.length=ic; // C 表的长度不一定是 A、B 表长度之和
    return OK;
}

void PrintSqList(SqList L) {
    cout << "线性表输出:";
    for (int i = 0; i < L.length; i++) cout << L.elem[i] << ' ';
    cout << '\n';
}

void InitSqList(SqList& L, int od) {
    cout << "(" << od << ")创建有 n 个元素的有序顺序表" << (char)('A' + od - 1) << "..." << '\n';
    do {
        cout << "请输入元素个数：";
        cin >> L.length;
    } while (L.length < 1 || L.length > MAXSIZE);
    if (CreatSqList(L)) cout << "有序线性表初始化成功！" << '\n';
    else cout << "有序线性表初始化失败" << '\n';
}

signed main() {
    SqList LA, LB, LC;
    InitSqList(LA, 1);
    InitSqList(LB, 2);
    MergeSort(LA, LB, LC);
    PrintSqList(LA);
    PrintSqList(LB);
    PrintSqList(LC);
}