/**
 * Problem: U653589
 * Tags: 
 * //GCD
 * Rating: 无
 * Link: 
 */

#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    cout << gcd(a, b) << '\n';
}