/**
 * Problem: AcWing 871. 约数之和
 * Tags:
 *  //数论
 *  //约数之和
 *  //质因子分解
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/873/
 */

#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    unordered_map<int, int> primes;
    while (n--) {
        int x; cin >> x;
        for (int i = 2; i <= x / i;  i++) {
            while (x % i == 0) {
                primes[i]++;
                x /= i;
            }
        }
        if (x > 1) primes[x]++;
    }

    int res = 1;
    for (auto [a, b] : primes) {
        int t = 1;
        while (b--) t = (a * t + 1) % MOD; 
        res = res * t % MOD;
    }
    cout << res << '\n';
}