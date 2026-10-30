#include <iostream>
using namespace std;
typedef long long ll;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    int d = exgcd(b, a % b, y, x);

    y -= a / b * x;

    return d;
}


void solve() {
    int a, b, x, y, m; cin >> a >> b >> m;
    int d = exgcd(a, m, x, y);
    
    if (b % d) puts("impossible");
    else cout << (ll)(b / d) * x % m << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}