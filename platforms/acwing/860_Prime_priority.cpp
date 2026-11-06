#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cstring>
#define rep(i, a, b) for (int i = (a); i < (b); i++) 

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 1e5 + 10;

int h[N], e[M<<1], w[M<<1], ne[M<<1], dist[N];
int n, m;
bitset<N> st;

void add(int a, int b, int c) {
    static int idx = 0;
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
}

int prime() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    int res = 0, cnt = 0;

    while (heap.size()) {
        auto t = heap.top(); heap.pop();

        int distance = t.first, ver = t.second;
        
        if (st[ver]) continue; st[ver] = 1; 
        cnt++;
        res += distance;
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];

            if (w[i] < dist[j]) { // !st[i] ?? 
                dist[j] = w[i];
                heap.push({dist[j], j});
            }

        }

    }

    if (cnt < n) return 0x3f3f3f3f;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    rep(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    int t = prime();
    if (t == 0x3f3f3f3f) cout << "impossible" << '\n';
    else cout << t << '\n';
}