#include <iostream>
#include <queue>
#include <bitset>
#include <cstring>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 1e5 + 10;

int h[N], e[M << 1], ne[M << 1], w[M << 1];
int n, m;
int dist[N];
bitset<N> st;

void init() {
    memset(dist, 0x3f, sizeof dist);
    memset(h, -1, sizeof h);
}

void add(int a, int b, int c) {
    static int idx = 0;
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int prime() {
    int cnt = 0, res = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;    //第一个点到集合的距离为 0，加入堆里

    while (heap.size()) {
        auto t = heap.top(); heap.pop();

        int u = t.second;

        if (st[u]) continue; st[u] = 1;
        cnt++; res += dist[u];  //做集合元素个数统计，并做总代价累加

        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (w[i] < dist[j]) {
                dist[j] = w[i]; //松弛更新权值
                heap.push({dist[j], j});
            }
        }
    }

    if (cnt < n) return 0x3f3f3f3f;     //集合里不够n 个点说明该图不连通
    else return res;    //反之找到了一颗最小生成树
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> m;

    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    int t = prime();
    t == 0x3f3f3f3f ? cout << "impossible" << '\n' : cout << t << '\n';

}