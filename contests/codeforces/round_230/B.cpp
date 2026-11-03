/**
 * Problem: CF 230B T-primes
 * Tags:
 *  //数论
 *  //线性筛
 *  //质数
 * Rating: 1300
 * Link: https://codeforces.com/problemset/problem/230/B
 */

#include <iostream>
#include <bitset>
using namespace std;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

ull a[N], prime[M];
bitset<M + 10> st;

void Lsieve() {
    int cnt = 0;
    for (int i = 2; i <= M; i++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i <= M / prime[j]; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

ull f_sqrt(ull x) {
    if (x == 0) return 0;
    ull num = 0;
    for (int i = 31; i >= 0; i--) {
        ull mid = num | (1ull << i);
        if (mid <= x / mid) num = mid; 
    }
    return num;
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) if (x % i == 0) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ull n; cin >> n;
    //Lsieve(); st[1] = 1;
    for (int i = 0; i < n; i++) {
        ull x; cin >> x;
        ull sq_x = f_sqrt(x);
        if (sq_x * sq_x == x && is_prime(sq_x)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}