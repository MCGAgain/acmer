#include <iostream>
#include <cstring>
#include <array>
#include <bitset>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

const int N = 110, M = 1e5 + 10;

int gra[N][N], n, m, dist[N];
bitset<N> st;

int prime() {

    memset(dist, 0x3f, sizeof dist);
    int res = 0;

    for (int i = 0; i < n; i++) {

        int t = -1;
        dist[1] = 0; // 为了定义上的美观，我们讲 dist[1]定义为0，实际上dist[1] 并不会被使用

        for (int j = 1; j <= n; j++) {
            if (!st[j] && (!~t/*t 为-1 的时候是当前的第一个点，最为最小值即可*/ || dist[j] < dist[t])) t = j;
        }

        // 如果没有初始化dist[1] = 0 那么必须加对i的特判
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;  //如果是非第一次，也就从第二轮开始建边的时候，无限大意味着不可达，不连通
        if (i) res += dist[t];  //t 作为当前确定的离集合最近的点，可以添加到结果中
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
    memset(gra, 0x3f, sizeof gra);

    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        gra[u][v] = gra[v][u] = min(gra[u][v], w);
    }

    int t = prime();
    if (t == 0x3f3f3f3f) cout << "impossible" << '\n';
    else cout << t << '\n';

}