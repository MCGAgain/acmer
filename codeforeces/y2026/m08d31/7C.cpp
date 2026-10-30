#include <iostream>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c, x, y; cin >> a >> b >> c;
    int d = exgcd(a, b, x, y);
    if ((-c) % d) cout << -1 << '\n';
    else cout << x * (-c) / d << ' ' << y * (-c) / d << '\n';
}