#include <iostream>
using namespace std;

int phi(int x) {
    int ans = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << phi(n) << '\n';
    }
}