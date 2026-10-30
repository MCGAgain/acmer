#include <iostream>
#define OK true
#define ERROR false
using namespace std;

typedef bool Status;
typedef int QElemType;

typedef struct QNode{ //链表结点类型
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct { //队列类型
    QueuePtr front; //队头指针
    QueuePtr rear; //队尾指针
}LinkQueue;

Status InitQueue(LinkQueue &Q) {

    Q.front= Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if(!Q.front) return ERROR;
    Q.front->next = NULL;
    return OK;
}
Status EnQueue(LinkQueue &Q, QElemType e){

    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) return ERROR;
    p->data = e;
    p->next=NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
Status DeQueue(LinkQueue &Q, QElemType &e){

    QueuePtr p;
    if(Q.rear==Q.front)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return OK;
}

bool IsEmpty(LinkQueue Q) {
    return Q.rear == Q.front;
}

void PrintYanghuiTriangle(int n) // 输出 n 行杨辉三角
{ LinkQueue Q;
    InitQueue(Q);
    QElemType pre = 0, cur = 1;
    printf("%d\n", 1);
    EnQueue(Q, 1); EnQueue(Q, 1);
    for(int i = 2; i <= n; i++) {
        pre = 0;
        for(int j = 0; j < i; j++) {
            DeQueue(Q, cur);
            printf("%d ", cur);
            EnQueue (Q, pre + cur);
            pre = cur;
        }
        puts(""); EnQueue (Q,1);
    }
}

signed main() {
    cout << "请输入行数:";
    int n; cin >> n;
    PrintYanghuiTriangle(n);
}