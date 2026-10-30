/**
 * Problem: AcWing 872. 最大公约数
 * Tags:
 *  //数论
 *  //欧几里得算法
 *  //GCD
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/874/
 */

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
}
 