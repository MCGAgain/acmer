/**
 * Problem: P3383 【模板】线性筛素数
 * Tags:
 *  //数论
 *  //线性筛
 *  //模板题
 * Rating: 普及/提高-
 * Link: https://www.luogu.com.cn/problem/P3383
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e8 + 10;
int n, q, cnt = 0;
int prime[N / 10];
bitset<N> st;

void Lsieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] <= n / i; j ++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    Lsieve();
    while (q--) {
        int x; cin >> x;
        cout << prime[x - 1] << '\n';
    }
}