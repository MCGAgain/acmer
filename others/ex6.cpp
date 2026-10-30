#define MAXN 20
#include<stdio.h>

void Fun(int M[MAXN][MAXN], int n)
{
    int i,j,k=0;
    for(i=0;i<(n+1)/2; i++) {
        for(j=i; j< n - i; j++) {    //产生第 i 圈左边的数字（从上到下）
            k++;
            M[j][i]=k;
        }
        for(j=i+1;j< n - i; j++) {  //产生第 i 圈下边的数字（从左到右）
            k++;
            M[n-i-1][j]=k;
        }
        for(j=n-i-2;j >= i; j--) {  //产生第 i 圈右边的数字（从下到上）
            k++;
            M[j][n-i-1]=k;
        }
        for(j=n-i-2;j>= i + 1; j--) {  //产生第 i 圈上边的数字（从右到左）
            k++;
            M[i][j]=k;
        }
    }
}

int main()
{
    int i,j,n;
    int M[MAXN][MAXN];
    while(1) {
        do {
            printf("\n 输入矩阵的阶(0-%d)(0:结束!)==>", MAXN-1);
            scanf("%d",&n);
        } while(n<0||n>=MAXN);
        if(n==0) return 0;
        Fun(M,n);
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++)
                printf("%4d",M[i][j]);
            printf("\n");
        }
    }
    return 0;
}