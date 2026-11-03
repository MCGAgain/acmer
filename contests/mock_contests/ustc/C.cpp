#include <iostream>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int N = 2e5;
int a[N];

void solve() {
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    int oddState = 0;
    rep(i, 0, n) {
        oddState ^= (a[i] & 1); //标志判断奇数个数
    }

    oddState &= (-1 ^ (1 << 31));  //去除高位1的负数影响

    if (n == 2) {
        if ((a[1] - a[0]) % 4 == 0) cout << 0 << '\n';
        else if ((a[1] - a[0]) % 2 == 0) cout << 2 << '\n';
        else cout << 1 << '\n';
        return;
    }

    if (oddState && !(n & 1)) cout << 1 << '\n';
    else cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; 
    while (T--) solve();
}