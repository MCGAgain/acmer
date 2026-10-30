#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 8
#define N 10
#define MAXS 100 // 栈的最大容量

#define OK 1
#define ERROR 0

typedef int Status;

// 定义位置坐标
typedef struct {
    int x, y;
} PosType;

// 定义迷宫数组类型
typedef char MazeType[M + 2][N + 2];

// 定义栈元素类型
typedef struct {
    int i;  // 当前位置的行下标
    int j;  // 当前位置的列下标
    int di; // 下一个探索方向 (0:下, 1:右, 2:上, 3:左)
} SElemType;

// 定义顺序栈类型
typedef struct {
    SElemType st[MAXS];
    int top;
} Stack;

// 迷宫寻路算法
Status MazePath(MazeType maze, Stack *S, PosType start, PosType end)
{
    int i, j, di, ftag;

    // 入口进栈，路径上的迷宫元素值置 -1（防止重复走入）
    S->top++;
    S->st[S->top].i = start.x;
    S->st[S->top].j = start.y;
    S->st[S->top].di = -1;
    maze[start.x][start.y] = -1;

    while (S->top > -1) // 栈非空循环
    {
        i = S->st[S->top].i;
        j = S->st[S->top].j;
        di = S->st[S->top].di; // 读栈顶元素

        if (i == end.x && j == end.y) // 已到达出口，存在路径
            return OK;

        ftag = 0;
        while (di < 4 && ftag == 0) // 寻找下一个可前进的位置 (i, j)
        {
            di++;
            switch (di) {
                case 0: // 向下
                    i = S->st[S->top].i + 1;
                    j = S->st[S->top].j;
                    break;
                case 1: // 向右
                    i = S->st[S->top].i;
                    j = S->st[S->top].j + 1;
                    break;
                case 2: // 向上
                    i = S->st[S->top].i - 1;
                    j = S->st[S->top].j;
                    break;
                case 3: // 向左
                    i = S->st[S->top].i;
                    j = S->st[S->top].j - 1;
                    break;
            }
            if (maze[i][j] == 0)
                ftag = 1;
        }

        if (ftag == 1) // 可以通过
        {
            S->st[S->top].di = di; // 修改栈顶元素的前进方向
            S->top++;
            S->st[S->top].i = i;
            S->st[S->top].j = j;
            S->st[S->top].di = -1; // 新位置进栈
            maze[i][j] = -1;       // 做标记
        }
        else // 四个方向均不能通过，进行回溯
        {
            maze[S->st[S->top].i][S->st[S->top].j] = 0; // 恢复标记，置为其它可能路径可通过
            S->top--; // 退栈
        }
    }
    return ERROR;
}

int main()
{
    MazeType maze;
    int i, j;
    Stack S;

    S.top = -1; // 初始化栈
    PosType start = {1, 1}, end = {M, N}; // 入口 (1,1)、出口 (M,N)

    srand((unsigned)time(NULL)); // 设置随机数种子

    // 用随机数生成迷宫内部数据（0 为通路，1 为障碍）
    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    // 设置迷宫四周外围为墙（元素为 1）
    for (i = 0; i <= M + 1; i++) {
        maze[i][0] = 1;
        maze[i][N + 1] = 1;
    }
    for (j = 0; j <= N + 1; j++) {
        maze[0][j] = 1;
        maze[M + 1][j] = 1;
    }

    // 确保起点和终点为通路
    maze[1][1] = 0;
    maze[M][N] = 0;

    // 输出当前生成的迷宫
    printf("迷宫输出：\n");
    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            printf("%3d", maze[i][j]);
        }
        printf("\n");
    }

    // 迷宫路径求解
    if (MazePath(maze, &S, start, end))
    {
        printf("迷宫路径如下：\n");
        // 从栈顶到栈底输出路径（由出口回溯到入口）
        for (i = S.top; i >= 0; i--)
        {
            printf(" (%d,%d)", S.st[i].i, S.st[i].j);
            if ((S.top - i + 1) % 6 == 0)
                printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf(" 无路径！\n");
    }

    return 0;
}