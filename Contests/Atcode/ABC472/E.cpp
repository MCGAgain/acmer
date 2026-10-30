#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;

int e[N * 2], ne[N * 2], h[N], idx = 0;
int n, m, color[N], ans;
//unordered_map<int, int> mapping;
vector<int> path;

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c)) {
                path.push_back(u);
                return false;
            }
        }
        else {
            if (color[j] == c) {
                path.push_back(u);
                return false;
            }
        }
    }

    return true;
}

void solve() {
    path.clear();
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        h[i] = -1;
        color[i] = 0;
    }
    idx = 0;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                cout << path.size() << '\n';
                for (auto i = path.rbegin(); i < path.rend(); i++) {
                    cout << (*i) << ' ';
                }
                cout << '\n';

                return;
            }
        }
    }

    cout << -1 << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}