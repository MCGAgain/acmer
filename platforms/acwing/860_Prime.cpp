#include <iostream>
#include <cstring>
#include <array>
#include <bitset>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

const int N = 510, M = 1e5 + 10;

int n, m;
int gra[N][N]; //邻接矩阵存边
int dist[N];    //点到集合的距离
bitset<N> st;   //判断该点是否已经在集合中

void init() {
    memset(dist, 0x3f, sizeof dist);    //初始化所有点到集合的距离都是正无穷
    memset(gra, 0x3f, sizeof gra);  //初始化每一条边的距离都是正无穷，表示边不存在，或者两点不连通
}

int prime() {

    int res = 0;
    dist[1] = 0; //规定起点到集合的距离就是 0，因为起点已经在集合中

    for (int i = 0; i < n; i++) {   //每次确定一个点到集合中，n 个点需要确定 n 次

        int t = -1;
        
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (!~t/*t 为-1 的时候是当前的第一个点，最为最小值即可*/ || dist[j] < dist[t])) t = j;
        }

        // 如果没有初始化dist[1] = 0 那么必须加对i的特判
        if (dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;  //在所有剩下的不在集合的点中找的到集合最近的点的距离都是无限大，说明剩下的点跟集合根本不连通
        res += dist[t];  //t 作为当前确定的离集合最近的点，可以添加到结果中; 起点到起点的距离为 0，不影响结果
        st[t] = 1;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], gra[t][j]);  //0x3f3f3f3f处理了不存在的边，保证了不会被松弛
            /*
            这里是增量维护，看似是只松弛了到 t 的最短距离，但是实际上，
            集合中除 t 以外的点，在历史中已经完成了松弛更新，属于历史纪录信息，
            所以我们只需要对新增点 t 完成松弛操作即可
            */

    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        gra[u][v] = gra[v][u] = min(gra[u][v], w);
    }

    int t = prime();
    if (t == 0x3f3f3f3f) cout << "impossible" << '\n';
    else cout << t << '\n';

}