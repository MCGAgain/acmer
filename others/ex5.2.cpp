#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define OK 1
#define ERROR 0

typedef int Status;

typedef struct {
    char *str;      //堆分配首地址
    int length;     //串长度分量,空串时,其值为0。
} HString;

Status StrAssign(HString *T, char *chars) {
    if (T->str != NULL) free(T->str); //每次操作,先释放T原有空间
    int i, k;
    for (k = 0; chars[k] != '\0'; k++); //计算chars的长度
    T->length = k;
    if (k == 0) T->str = NULL;
    else {
        T->str = (char *)malloc(k * sizeof(char));
        if (!(T->str))
            return ERROR; // 分配空间失败
        for (i = 0; i < k; i++)
            T->str[i] = chars[i];
    }
    return OK;
}

// 朴素的模式匹配算法
int Index(HString S, HString T, int pos) {
    //返回模式串在主串S中第pos个字符之后的位置。若不存在,返回0
    //其中T非空, pos=1..T.length
    int i = pos, j = 1;
    while(i <= S.length && j <= T.length) {
        printf("(%d,%d)", i, j);
        if(S.str[i-1] == T.str[j-1])
            { i++; j++; } //前面匹配成功,继续向后匹配
        else {
            i = i - j + 2;
            j = 1;
        }
        //指针后退重新开始匹配
    }
    printf("\n");
    if(j > T.length) return i - T.length;
    else return 0;
}

//计算模式串的 next 值
void GetNext(HString T, int next[]) {
    //求模式串的next函数值并存入数组next.
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length) {
        if(j == 0 || T.str[i-1] == T.str[j-1]) {
            i++; j++;
            next[i] = j;
        }
        else j = next[j];
    }
}

// 计算求模式串的next函数修正值
void GetNextval(HString T, int next[]) {
    //求模式串T的next函数修正值,并存入数组 next
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length) {
        if(j == 0 || T.str[i-1] == T.str[j-1]) {
            ++i; ++j;
            if(T.str[i-1] != T.str[j-1]) next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

// KMP算法
int IndexKMP(HString S, HString T, int pos, int next[]) {
    //利用模式串T的next函数求T在主串S中第pos个字符之后的位置
    //算法为KMP算法。其中,T非空,pos=1..S.length
    int i = pos, j = 1;
    while(i <= S.length && j <= T.length) {
        printf("(%d,%d)", i, j);
        if(j == 0 || S.str[i-1] == T.str[j-1]) { i++; j++; } //前面匹配成功,继续向后匹配
        else j = next[j]; //模式串右移
    }
    printf("\n");
    if(j > T.length) return i - T.length; //匹配成功,返回模式串主串中的位置
    else return 0;
}

// 串输出
Status OutString(HString T) {
    for (int i = 0; i < T.length; i++)
        printf("%c", T.str[i]);
    printf("\n");
    return OK;
}

int main() {
    printf("-------串的模式匹配实验-------\n");
    char instr[100];
    HString S, T;
    S.str = T.str = NULL;
    int i = 0, k, pos = 1;
    int *next;

    printf("1.创建一个主串.\n");
    printf("请输入主串:");
    scanf("%s", instr);
    StrAssign(&S, instr);
    printf("当前主串值是:");
    OutString(S);

    printf("2.创建一个模式串.\n");
    printf("请输入模式串:");
    scanf("%s", instr);
    StrAssign(&T, instr);
    next = (int*)malloc((T.length + 1) * sizeof(int));
    printf("当前模式串值是:");
    OutString(T);

    printf("3.朴素的模式匹配算法匹配过程:\n");
    k = Index(S, T, pos);
    if(k > 0) 
        printf("匹配成功!模式串在主串的位置是:%d\n", k);
    else printf("匹配失败!\n");
    getchar();

    printf("4.模式匹配的KMP算法匹配过程:\n");
    GetNext(T, next);
    k = IndexKMP(S, T, pos, next);
    if(k > 0)
        printf("匹配成功!模式串在主串的位置是:%d\n", k);
    else
        printf("匹配失败!\n");
    getchar();

    printf("5.模式匹配的KMP(修正)算法匹配过程:\n");
    GetNextval(T, next);
    k = IndexKMP(S, T, pos, next);
    if(k > 0)
        printf("匹配成功!模式串在主串的位置是:%d\n", k);
    else
        printf("匹配失败!\n");
    getchar();

    //释放内存
    if(S.str) free(S.str);
    if(T.str) free(T.str);
    if(next) free(next);
    return 0;
}
