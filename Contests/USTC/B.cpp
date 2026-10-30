#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
typedef long long ll;
using namespace std;

const int N = 5e3 + 10;
int a[N];

void solve() {
    int n; cin >> n;

    rep(i, 1, n) cin >> a[i];
    int t = n / 2, exChange = 0;

    for (int i = 1; i <= n - 1; i++) {

        bool hasChange = false;
        for (int j = 1; j <= n - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                hasChange = true;
                exChange++;
            }
        }
        if (!hasChange) break;

    }

    // rep(i, 1, n) cout << a[i] << ' ';
    // cout << '\n';
    int ans = exChange + t;

    //cout << exChange << ' ' << t << '\n';
    if (ans & 1) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}