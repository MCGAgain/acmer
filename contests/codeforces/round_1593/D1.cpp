#include <iostream>
#include <algorithm>
using namespace std;

const int N = 45, M = 2e6 + 10;
int a[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, min_num = 1e9; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            min_num = min(a[i], min_num);
        }
        for (int i = 0; i < n; i++) a[i] -= min_num;
        int g = a[0]; bool tag = false;
        for (int i = 1; i < n; i++) {
            g = gcd(a[i], g);
            if (a[i] != a[i - 1]) tag = true; //注意全局为空特判
        }
        if (tag) cout << g << '\n';
        else cout << -1 << '\n';
    }
}