#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m, p[N], res = 0;

struct Edge {
    int a, b, w;
    bool operator<(const Edge o) const {
        return this->w < o.w;
    }
} edges[M];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

bool kruskal() {
    int cnt = 0;

    rep(i, 0, m) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            cnt++;
            p[a] = b;
            res += w;
        }
    }

    if (cnt < n - 1) return false;
    else return true;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    rep(i, 0, n + 1) p[i] = i; 
    rep(i, 0, m) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }

    sort(edges, edges + m);

    if (kruskal()) cout << res << '\n';
    else cout << "impossible" << '\n';

}