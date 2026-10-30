#include <iostream>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;
const int N = 2e5 + 10;
int a[N];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> k >> n; rep(i, 0, n) cin >> a[i];

    int ans = a[n - 1] - a[0];
    rep(i, 1, n) {
        int iToStart = a[i - 1], startToi1 = k - a[i];
        ans = min(ans, iToStart + startToi1);
    }

    cout << ans << '\n';

}