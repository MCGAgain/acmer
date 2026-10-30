#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

int a[100];

void solve() {
    int n; cin >> n;
    int l, r;
    for (int i = 0; i < n; i++) cin >> a[i];
    l = a[0], r = a[n - 1];
    int cnt_zero = 0;
    for (int i = 1; i < n - 1; i++) if (!a[i]) cnt_zero++;
    if (l + r <= cnt_zero) {
        cout << l + r << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}