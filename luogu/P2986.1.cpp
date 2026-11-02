#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 1e5 + 10;

array<int, N> cows, h, size, path;
array<int, N << 1> ne, e, w;

int cow_sum = 0, center = 0, best = 0x3f3f3f3f;

void add(int a, int b, int x) {
    static int idx = 0;
    e[idx] = b, w[idx] = x, ne[idx] = h[a], h[a] = idx++;
}

void find_center (int u, int f) {
    size[u] = cows[u];  //初始化当前节点的 size
    int max_sub = -1;   //最大的子树重量


    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != f) {
            find_center(j, u);
            size[u] += size[j];
            max_sub = max(max_sub, size[j]);    //选择子树中节点权重最大的
        } 
    }

    max_sub = max(max_sub, cow_sum - size[u]);  //与父部组成的子树的再次比较

    if (max_sub < best) {
        center = u;
        best = max_sub;
    }
    
}

void set_path(int u, int f) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != f) {
            path[j] += path[u] + w[i];
            set_path(j, u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(&h, -1, sizeof h);

    int n; cin >> n;
    rrep(i, 1, n) {
        cin >> cows[i];
        cow_sum += cows[i];
    }

    rep(i, 1, n) {
        int a, b, x;
        cin >> a >> b >> x;
        add(a, b, x);
        add(b, a, x);
    }


    find_center(1, 0);
    set_path(center, 0);

    int ans = 0;
    rrep(i, 1, n) ans += path[i] * cows[i];
    
    cout << ans << '\n';

}