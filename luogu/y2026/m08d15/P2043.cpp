/**
 * Problem: P2043 质因子分解
 * Tags:
 *  //数论
 *  //质因子分解
 *  //试除法
 * Rating: 普及-
 * Link: https://www.luogu.com.cn/problem/P2043
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e5 + 10;
int cnt[N], n;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        while (x % i == 0) {
            x /= i;
            cnt[i]++;
        }
    }
    if (x > 1) cnt[x]++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        divide(i);
    }
    for (int i = 1; i <= n; i++) if (cnt[i]) cout << i << ' ' << cnt[i] << '\n';
}