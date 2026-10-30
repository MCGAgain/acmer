/**
 * Problem: CF 1203C Common Divisors
 * Tags:
 *  //数论
 *  //GCD
 *  //约数个数
 * Rating: 1300
 * Link: https://codeforces.com/problemset/problem/1203/C
 */

#include <iostream>
#define int long long
using namespace std;

const int N = 4e5 + 10;
int a[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; } 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, cnt = 0; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int g = a[0];
    for (int i = 0; i < n; i++) g = gcd(g, a[i]);
    int ans = 1;
    for (int i = 2, p = 0; i <= g / i; i++, p = 0) {
        while (g % i == 0) {
            p++;
            g /= i;
        }
        ans *= (p + 1);
    }
    if (g > 1) ans *= 2;
    cout << ans << '\n';
}