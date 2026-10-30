/**
 * Problem: P1734
 * Tags:
 *  //约数之和
 *  //背包DP
 *  //DP
 * Rating: 普及-
 * Link: https://www.luogu.com.cn/problem/P1734
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#define int long long
using namespace std;

const int N = 1e3 + 10;
int n, s[N], f[N];

void init() {
    unordered_map<int, int> primes;
    for (int i = 2; i <= n; i++) {
        primes.clear();
        int x = i;
        for (int j = 2; j <= x / j; j++) {
            while (x % j == 0) {
                primes[j]++;
                x /= j;
            }
        }
        if (x > 1) primes[x]++;
        int sum = 1;
        for (auto [a, b] : primes) {
            int t = 1;
            while (b--) t = a * t + 1; 
            sum *= t;
        }
        s[i] = sum - i;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) 
        for (int j = n; j >= i; --j) 
            f[j] = max(f[j], f[j - i] + s[i]);
    cout << f[n] << '\n';
}