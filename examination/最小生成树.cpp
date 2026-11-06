#include<stdio.h>
#define INF 32767                 //表∞
#define MAXE 100                  //最大边数
#define MAXV 30                   //最大顶点数
typedef int InfoType;             //添加顶点信息的类型定义
typedef struct {                  //定义图的顶点结构
    int no;                       //顶点编号
    InfoType  info;               //顶点其它信息
} VertexType;
typedef struct {                  //定义图邻接矩阵
    VertexType vexs[MAXV];        //顶点向量
    int arcs[MAXV][MAXV];         //邻接矩阵
    int vexnum, arcnum;           //图的当前顶点数和边数
} MGraph;
typedef struct {                  //Prim 算法所用辅助结点
    int     adjvex;
    int     lowcost;
}cledge;
typedef struct {                  // Kruskal 算法中边集 E 的每条边
    int  u;                       // 边的起始顶点号
    int  v;                       // 边的终止顶点号
    int  w;                       // 边的权值
} Edge;


void CreatMG(MGraph &mg)                    // 建立图的邻接矩阵
{   int i,j;
    int A[7][7];                            // 临时数组
    mg.vexnum=7;                            // 指定有 7 个顶点
    mg.arcnum=9;                            // 指定有 9 条边
    for(i=0; i<mg.vexnum; i++)
        for(j=0; j<mg.vexnum; j++)
            A[i][j]=INF;
    A[0][1]=5; A[0][2]=4; A[0][6]=1; // 为邻接矩阵上三角赋值
    A[1][3]=13;
    A[2][3]=3; A[2][5]=8; A[2][6]=15;
    A[3][4]=2;
    A[5][6]=11;
    for(i=1; i<mg.vexnum; i++)              // 为邻接矩阵下三角赋值
        for(j=0; j<i; j++)
            A[i][j]=A[j][i];
    for(i=0; i<mg.vexnum; i++)
        for(j=0; j<mg.vexnum; j++)
            mg.arcs[i][j]=A[i][j];
}
void OutputMG(MGraph mg)                    //输出图的邻接矩阵
{   int i, j;
    for(i=0; i<mg.vexnum; i++)
    {   for(j=0; j<mg.vexnum; j++)
            if(mg.arcs[i][j]==INF)
                printf("  ∞");
            else
                printf("%4d", mg.arcs[i][j]);
        printf("\n");
    }
}
void Prim(MGraph G, int u)                  // Prim 算法
{   int i, j, k,min;
    cledge closedge[MAXV];
    for(j=0; j<G.vexnum; ++j)               //辅助数组初始化
        if(j!=u)
        {   closedge[j].adjvex=u;
            closedge[j].lowcost=G.arcs[u][j];
        }
    closedge[u].lowcost = 0;                //初始,U={u}
    for(i = 1; i<G.vexnum; ++i)             //找出 n-1 个顶点
    {   min=INF; k=0;
        for(j=0; j<G.vexnum; j++)           //在（V-U）中找出离 U 最近的顶点 k,权为 min
            if(closedge[j].lowcost!=0 && closedge[j].lowcost<min)
            {   min= closedge[j].lowcost;   // min 取较小的权值
                k= j; // k 取较小权值对应的顶点号 (1)
            }
        printf(" %d，(%d，%d)：%d\n",k, closedge[k].adjvex, k, min);
        closedge[k].lowcost = 0;            //顶点 k 并入 U 集合
        for(j = 0; j < G.vexnum; ++j)
            if (G.arcs[k][j] < closedge[j].lowcost)
            {   closedge[j].adjvex=k;
                closedge[j].lowcost=G.arcs[k][j];   //(2)
            }
    }//for
}//Prim
void SortEdge(MGraph G, Edge E[])           // Kruskal 算法按边的权值排序，结果存于 E 中
{   //用有序直接插入法构造有序边集 E
    int  i , j, k, c=0;                     // c 用于统计加入到 E 中的边数
    for(i=0; i<G.vexnum; i++)
        for(j=i+1; j<G.vexnum; j++)
            if(G.arcs[i][j]<INF)
            {
                for(k=c-1; k>=0 && E[k].w>G.arcs[i][j]; k--)    //定位插入点
                    E[k+1]=E[k];
                E[k+1].u=i;              // 插入点为 k+1
                E[k+1].v=j;
                E[k+1].w=G.arcs[i][j];
                c++;
            }
}
void Kruskal(Edge E[], int n, int e){
    int i, j, k, m1, m2, sn1, sn2;
    int vset[MAXE];
    for(i=0; i<n; i++)    vset[i]=i;        //初始化辅助数组
    k=1;                                    //每选中一条边，计数器 k 加 1
    j=0;                                    //每次从 E 中取第 j 条边
    while(k<n)                              //总共需要选出 n-1 条边
    {
        m1=E[j].u; m2=E[j].v;               //边的两个顶点号
        sn1=vset[m1]; sn2=vset[m2];
        if(sn1!=sn2)                 //若不等，则依附于该条边的两个顶点不在同一连通分量
        {
            printf(" (%d，%d)：%d\n", m1, m2, E[j].w);   //输出该边及权值
            k++;                        //生成边数加 1
            for(i=0; i<n; i++)
                if(vset[i]==sn2)
                    vset[i]=sn1;
        }
        j++;                            //取 E 中下一条边
    }
}
int main()
{
    int u=0;
    MGraph  mg;
    Edge    E[MAXE];
    printf("（1）构造图的邻接矩阵……\n");
    CreatMG(mg);
    printf("（2）当前图的邻接矩阵如下：\n");
    OutputMG(mg);
    getchar();
    printf("（3）普里姆（Prim）算法求解结果如下：\n");
    Prim(mg, u);
    getchar();
    printf("（4）克鲁斯卡尔（Kruskal）算法求解结果如下：\n");
    SortEdge(mg, E);
    Kruskal(E, mg.vexnum, mg.arcnum);
    return 0;
}