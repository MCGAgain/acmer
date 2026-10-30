/**
 * Problem: P1865 A % B Problem
 * Tags:
 *  //数论
 *  //线性筛
 *  //前缀和
 * Rating: 普及-
 * Link: https://www.luogu.com.cn/problem/P1865
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e6 + 10;
int prime[N], s[N], n, t, cnt = 0;
bitset<N> st;

void Lsieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            s[i] = s[i - 1] + 1;
        }
        else s[i] = s[i - 1];
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t >> n;
    Lsieve();
    while (t--) {
        int l, r; cin >> l >> r;
        if (l < 1 || r > n) {
            cout << "Crossing the line" << '\n';
            continue;
        }
        cout << s[r] - s[l - 1] << '\n';
    }

}