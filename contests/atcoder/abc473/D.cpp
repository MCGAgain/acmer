#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define int long long
typedef long long ll;
using namespace std;

int n, k;
vector<int> path;

void solve(int len, int sum) {
    if (sum > k) return;

    if (len == n - 1) {
        if ((k - sum )% (len + 1) != 0) return;
        path.push_back((k - sum) / (len + 1));
        for (auto x : path) cout << x << ' ';
        cout << '\n';
        path.pop_back();
        return;
    }

    for (int i = 0, t = i * (len + 1); t <= k - sum; i++) {
        t = i * (len + 1);
        path.push_back(i);
        solve(len + 1, sum + t);
        path.pop_back();

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    solve(0, 0);

}