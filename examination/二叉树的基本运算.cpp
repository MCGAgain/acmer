#include<stdio.h>
#include<stdlib.h>


typedef struct BiTNode {                // 定义二叉树的结点结构
    char data;                          // 假定树结点的元素类型为 char
    struct BiTNode *lchild;             // 左指针
    struct BiTNode *rchild;             // 右指针
} BiTNode,*BiTree;


void CreateBiTree(BiTree &T)
{   // 先序递归遍历方式创建一棵二叉树
    char ch;
    scanf("\n%c",&ch);                                   // 输入根结点的值
    if (ch =='#')                                        // 终止项
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));             // 创建根结点
        if (!T)
            exit(-1);
        T->data = ch;
        printf("\n 请输入 %c 结点的左子结点 ( 输入符号# 表示无 ):",T->data ); // 先序遍历创建左子树
        CreateBiTree(T->lchild);
        printf("\n 请输入 %c 结点的右子结点 ( 输入符号# 表示无 ):",T->data ); // 先序遍历创建右子树
        CreateBiTree(T->rchild);
    }
}


//统计二叉树的叶子结点个数。
int LeafNodeCount(BiTree T)
{
    if(T==NULL)
        return 0;                  //如果是空树，则叶子结点个数为 0
    else if(T->lchild == NULL && T->rchild == NULL)  //(1)
        return 1;//判断该结点是否是叶子结点(左孩子右孩子都为空),若是则返回 1
    else
        return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);
}


//交换二叉树每个结点的左孩子和右孩子。
void ChangeLR(BiTree T)
{
    BiTree p;
    if(T==NULL||(T->lchild==NULL&&T->rchild==NULL))
        return;
    else
    {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }
    ChangeLR(T->lchild);
    if(T==NULL||(T->lchild==NULL&&T->rchild==NULL)) // 交换右子树上结点的左右孩子(2)
        return;
    else
    {
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }          
}
// 统计二叉树中度为 1 的结点数
int D1_Nodes(BiTree T)
{
    int   num1, num2;
    if(T==NULL||(!T->lchild&&!T->rchild))
        return 0;
    num1=D1_Nodes(T->lchild);
    num2=D1_Nodes(T->rchild);
    if(T->lchild && !T->rchild) // 若结点 T 的左子树非空，右子树空，则返回左
                                // 子树上度为 1 的结点数加 1（当前结点度为 1）
        return num1 + 1; //(3)
    else if(!T->lchild && T->rchild)
        return num2+1;
    else
        return num1+num2;
}


//求二叉树结点数目
int Nodes(BiTree T)
{
    int num1,num2;
    if(T==NULL)
        return 0;
    else {
        num1=Nodes(T->lchild);                       // 统计左子树的结点数
        num2=Nodes(T->rchild);                       // 统计右子树的结点数
        return  num1 + num2 + 1;   //(4)        // 左右子树结点总数加 1（当前结点）
    }
}


// 求二叉树的深度
int BiTreeDepth(BiTree T)
{
    int leftdep, rightdep;
    if(T == NULL)   //(5)                    // 终止项
        return 0;
    else
    {
        leftdep=BiTreeDepth(T->lchild);
        rightdep=BiTreeDepth(T->rchild);
        return (leftdep>rightdep)? (leftdep+1):(rightdep+1);
    }
}
//以括号表示格式输出二叉树
void OutputBiTree(BiTree T)
{   // 先序递归遍历方式输出括号表示的二叉树
    if(T!=NULL)                                      // 终止项
    {
        printf("%c", T->data);                       // 访问根结点
        if(T->lchild!=NULL||T->rchild!=NULL)
        {
            printf("(");                             // 根的孩子用圆括号对括
            OutputBiTree(T->lchild);                 // 先序遍历输出左子树
            if(T->rchild!=NULL)
                printf("，");                        // 根的左右孩子以“，”分隔
            OutputBiTree(T->rchild);                 // 先序遍历输出右子树
            printf(")");                             // 根的孩子用圆括号对括
        }
    }
}
int main()
{   int n;
    BiTNode *proot;                                  // 定义树
    proot=NULL;                                      // 初始化为空树
    printf("请输入根结点元素(输入符号#表示无):");       // 创建二叉树
    CreateBiTree(proot);
    printf("\n(1)二叉树创建成功！其括号表示格式输出：\n\t");
    OutputBiTree(proot);
    printf("\n");
    n=Nodes(proot);
    printf("(2)二叉树结点总数是：%d\n",n);
    n=LeafNodeCount(proot);
    printf("(3)二叉树的叶子结点数为：%d\n",n);
    n=BiTreeDepth(proot);
    printf("(4)二叉树的深度是：%d\n",n);
    n=D1_Nodes(proot);
    printf("(5)二叉树中度为 1 的结点数是：%d\n",n);
    ChangeLR(proot);
    printf("(6)交换所有结点的左右孩子后二叉树括号表示法输出：\n\t");
    OutputBiTree(proot);
    printf("\n");
    return 0;
}