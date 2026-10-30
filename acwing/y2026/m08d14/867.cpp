/**
 * Problem: AcWing 867. 分解质因数
 * Tags:
 *  //数论
 *  //试除法
 *  //质因子分解
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/869/
 */

#include <iostream>
using namespace std;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            cout << i << ' ' << cnt << '\n';
        }
    }
    if (x > 1) cout << x << ' ' << 1 << '\n';
    puts("");
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        divide(x);
    }
}
