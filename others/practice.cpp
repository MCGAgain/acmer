#include <iostream>
#define int long long

using namespace std;

int exgcd(int a, int b, int x, int y) {
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
    cin.tie(0);
    int n; cin >> n; while (n--) {
        int a, m, x, y, b; cin >> a >> b >> m;
        int d = exgcd(a, -m, x, y);
        if (b % d) cout << "impossible" << '\n';
        else cout << (b / d * x) % m << '\n';
    }
}