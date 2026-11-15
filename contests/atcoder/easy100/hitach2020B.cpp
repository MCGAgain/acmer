#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, m; cin >> A >> B >> m;
    vector<int> a(A), b(B);

    int min_a = 1e9, min_b = 1e9;
    rep(i, 0, A) {
        cin >> a[i];
        min_a = min(min_a, a[i]);
    }
    rep(i, 0, B) {
        cin >> b[i];
        min_b = min(min_b, b[i]);
    }

    int ans = min_a + min_b;

    while (m--) {
        int x, y, c; cin >> x >> y >> c;
        ans = min(ans, a[x - 1] + b[y - 1] - c);
    }

    cout << ans << endl;
}