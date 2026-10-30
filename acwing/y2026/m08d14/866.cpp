/**
 * Problem: AcWing 866. 试除法判定素数
 * Tags:
 *  //数论
 *  //试除法
 *  //质数判定
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/868/
 */

#include <iostream>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) if (x % i == 0) return false;
    return true; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        if (is_prime(x)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}