/**
 * Problem: 236B
 * Tags:
 *  //数论
 *  //DP
 *  //线性筛
 *  //约数个数
 * Rating: 1300
 * Link: https://codeforces.com/problemset/problem/236/B
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 110, MOD = 1073741824, M = 1e6 + 10;
int d[M];

#define S3
#ifdef S1
void solve() {
    for (int i = 1, ans = 1; i <= M; i++, ans = 1) {
        int x = i;
        for (int j = 2; j <= x / j; j++) {
            int p = 0;
            while (x % j == 0) {
                p++;
                x /= j;
            }
            ans *= (p + 1);
        }
        if (x > 1) ans *= 2;
        d[i] = ans;
    }
}
#endif

#ifdef S2
void solve() {
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) d[j]++;
    }
}

#endif

#ifdef S3

bitset<M> st;
int num[M], prime[M], cnt = 0;

void solve () {
    d[1] = 1;
    for (int i = 2; i <= M; i++) {
        if (!st[i]) {
            d[i] = 2, num[i] = 1;
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && i <= M / prime[j]; j++) {
            int t = i * prime[j];
            st[t] = 1;
            if (i % prime[j] != 0) {
                num[t] = 1;
                d[t] = 2 * d[i];
            }
            else {
                num[t] = num[i] + 1;
                d[t] = d[i] / (num[i] + 1) * (num[i] + 2);
                break;
            }
        }
    }
}

#endif

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    int a, b, c, sum = 0;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++) 
        for (int j = 1; j <= b; j++) 
            for (int k = 1; k <= c; k++) 
                sum = (sum + d[i * j * k]) % MOD;

    cout << sum << '\n';
}