/**
 * Problem: AcWing 870. 约数个数
 * Tags:
 *  //数论
 *  //约数个数
 *  //质因子分解
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/872/
 */

#include <iostream>
#include <unordered_map>
#define int long long
using namespace std;

unordered_map<int, int> primes;

const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                primes[i]++;
                x /= i;
            }
        }
        if (x > 1) primes[x]++;
    }
    int res = 1;
    for (auto x : primes) res = res * (x.second + 1) % MOD;

    cout << res << '\n';
}