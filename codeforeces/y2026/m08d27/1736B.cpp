/**
 * Problem: 1736B
 * Tags: 
 * Rating: 
 * Link: https://codeforces.com/problemset/problem/1736/B?utm_source=chatgpt.com
 */

#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
// int lcm(int a, int b) {
//     return a / gcd(a, b) * b;
// }

// void solve() {
//     int n; cin >> n;
//     a[0] = a[n + 1] = 1;
//     for (int i = 1; i <= n; i++) cin >> a[i];
    
//     for (int i = 1; i <= n + 1; i++) {
//         b[i] = lcm(a[i - 1], a[i]);
//     }
    
//     for (int i = 1; i <= n; i++) {
//         if (gcd(b[i], b[i + 1]) != a[i]) {
//             cout << "NO" << '\n';
//             return;
//         }
//     }
//     cout << "YES" << '\n';
// }

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n - 1; i++) {
        if (a[i] % gcd(a[i - 1], a[i + 1]) != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}