#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 510, M = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m;
int gra[N][N];  //邻接矩阵存边
int dist[N];    //该点到源点的最短路径长度
bitset<N> st;   //记录该点的最短路径有没有被确定

void init() {
    memset(dist, 0x3f, sizeof dist);    //初始化所有点到集合的距离都是正无穷
    memset(gra, 0x3f, sizeof gra);  //初始化每一条边的距离都是正无穷，表示边不存在，或者两点不连通
}

int Djikstra() {
    dist[1] = 0;    // 初始化起点到起点的距离为 0

    for (int i = 1; i <= n; i++) {

        int t = -1;
        for (int j = 1; j <= n; j++) 
            if (!st[i] && (!~t || dist[j] < dist[t])) t = j;

        if (dist[t] == INF) return INF;
        st[t] = 1;

        for (int j = 1; j <= n; j++) 
            dist[j] = min(dist[j], dist[t] + gra[t][j]);
    }
    
    return dist[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    init();

    rep(i, i, m) {
        int a, b, c; cin >> a >> b >> c;
        gra[a][b] = gra[b][a] = min(c, gra[a][b]); // 在这条边上的所有重边只保留最小的
    }



}