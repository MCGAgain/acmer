#include <iostream>
#include <array>
#include <algorithm>
#include <cstring>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e5 + 10;

array<int, N> h, cows, size, path;
array<int, N << 1> ne, e, w;
int n, idx = 0, best = 0x3f3f3f3f, center, cow_sum = 0;

void add(int a, int b, int x) {
    e[idx] = b, ne[idx] = h[a], w[idx] = x, h[a] = idx++;
}

void find_center(int u, int f) {
    size[u] = cows[u];

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != f) {
            find_center(j, u);
        }
    }

    int max_sub = 0;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != f) {
            size[u] += size[j];
            max_sub = max(max_sub, size[j]);
        }
    }
    max_sub = max(max_sub, cow_sum - size[u]);
    if (max_sub < best) {
        best = max_sub;
        center = u;
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
    cin >> n;
    rrep(i, 1, n) {
        cin >> cows[i];
        cow_sum += cows[i];
    }

    rrep(i, 1, n - 1) {
        int a, b, x; cin >> a >> b >> x;
        add(a, b, x);
        add(b, a, x); 
    }

    find_center(1, 0);
    set_path(center, 0);

    int ans = 0;
    rrep(i, 1, n) ans += path[i] * cows[i];

    cout << ans << '\n';
}