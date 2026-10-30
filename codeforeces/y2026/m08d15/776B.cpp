/**
 * Problem: CF 776B Sherlock and his girlfriend
 * Tags:
 *  //数论
 *  //构造
 *  //线性筛
 * Rating: 1100
 * Link: https://codeforces.com/problemset/problem/776/B
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e5 + 10;
int cnt = 0, n, prime[N];
bitset<N> st;

void Lsieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; n++;
    Lsieve();
    if (n < 4) cout << 1 << '\n';
    else cout << 2 << '\n';
    for (int i = 2, p = 2; i <= n; i++) {
        if (!st[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
}