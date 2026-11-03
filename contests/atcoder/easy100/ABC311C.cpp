#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 2e5 + 10;

int a[N];
bitset<N> vis;
vector<int> path, ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int p = 1;
    while (!vis[p]) {
        vis[p] = 1;
        path.push_back(p);
        p = a[p];
    } 

    bool tag = false;
    for (auto x : path) {
        if (x == p) tag = true;
        if (tag) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    

}