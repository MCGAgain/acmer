#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <algorithm>
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
ll a[N], k[N], b[N];

void solve() {
    int n; cin >> n;

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    for (int i = n; i >= 1; i--) {
        ll sk = 0, sb = 0;

        for (int j = 2 * i; j <= n; j += i) sk += k[j]; sb += b[j];
        k[i] = 1 - sk; b[i] = a[i] - sb;
    }

    ll L = mx, R = 4e18;
    for (int i = 1; i <= n; i++) {
        if (k[i] > 0) L = max(L, (ll)ceil((double)b[i] / k[i]));
        else if (k[i] < 0) R = min(R, (ll)floor((double)b[i] / k[i]));
        else {
            if (b[i] > 0) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    if (L <= R) cout << L - a[1] << "\n";
    else cout << -1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T = 1;
    while (T--) solve();

    return 0;
}