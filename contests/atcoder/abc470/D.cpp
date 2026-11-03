#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
vector <int> f(N), g(N);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) g[f[i]] = i;

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            int vx = f[x], vy = f[y];
            swap(f[x], f[y]);
            swap(g[vx], g[vy]);

        }
        else {
            f.swap(g);
        }
    }

    for (auto x : f) cout << x << ' ';
    cout << '\n';

}