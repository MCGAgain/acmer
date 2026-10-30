#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
typedef long long ll;
using namespace std;



void solve() {
    int n; cin >> n;
    vector<int> a(n + 10), b(n + 10);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        cin >> b[i];
        b[i] -= a[i];
    }
    int idx = 0;
    bool hasZero = false, headZero = b[0], tailZero = b[n - 1];

    // rep(i, 0, n) cout << b[i] << ' ';
    // cout << '\n';

    vector<int> st(n + 10, 2e9);
    rep(i, 0, n) {
        if (b[i] != st[idx]) st[++idx] = b[i];
        if (b[i] == 0) hasZero = true;
    }


    rep(i, 0, n) cout << st[i] << ' ';
    cout << '\n';

    cout << idx << ' ' << hasZero << '\n';

    cout << idx - (int)hasZero << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}