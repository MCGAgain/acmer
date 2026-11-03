#include <iostream>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, x, y; cin >> a >> b;
    int d = exgcd(a, b, x, y);
    int ans = x;
    if (ans < 0) while (ans < 0) ans += (b / d);
    else {
        while (ans >= 0) ans -= (b / d);
        ans += (b / d);
    }

    cout << ans << '\n';
}