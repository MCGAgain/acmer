#include <iostream>
#define Status int
#define ERROR false
#define OK true
#define Elemtype int

using namespace std;

typedef struct Node {
    Elemtype data;
    Node *next;
}Node, *LinkList;

Status CreatNode(LinkList& L, Elemtype data) {
    Node *p;
    if (!(p = new Node)) return ERROR;
    p->data = data;
    p->next = L->next;
    L->next = p;
    return OK;
}

Status CreatLinkList(LinkList& L) {
    Elemtype data;
    while (true) {
        cout << "请输入节点数据->";
        cin >> data;
        if (data == 0) break;
        if (!CreatNode(L, data)) return ERROR;
    }
    return OK;
}

void ReverseLinkList(LinkList& L) {
    Node *p = L->next, *q;
    L->next = NULL;
    while (p) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

void PrintLinkList(LinkList L) {
    Node *p = L->next;
    cout << "L->";
    while (p) {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "/\\" << '\n';
}

signed main() {
    LinkList L;
    if (!(L = new Node)) return -1;
    L->next = NULL;
    cout << "(1)输入若干数据创建链表...输入 0 结束" << '\n';
    if (CreatLinkList(L)) {
        cout << "链表创建成功!" << '\n';
        cout << "原始链表:";
        PrintLinkList(L);
    }
    else {
        cout << "链表创建过程中失败..." << '\n'; return -1;
    }
    cout << "(2)开始链表逆置..." << '\n';
    ReverseLinkList(L);
    cout << "链表逆置完成:";
    PrintLinkList(L); 
}