/**
 * Problem: P1218 [USACO1.5] 特殊质数肋骨 Special Prime Rib
 * Tags:
 *  //搜索
 *  //DFS
 *  //质数判定
 * Rating: 普及-
 * Link: https://www.luogu.com.cn/problem/P1218
 */

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N = 1e9 + 10;
vector<int> prime = {1, 3, 7, 9};
vector<int> a = {2, 3, 5, 7};
bitset<N> primes;
bitset<N> vis;
int n;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) if (x % i == 0) return false;
    return true;
}

void solve(int x, int size) {
    if (size == n) cout << x << '\n';
    for (int i = 0; i < prime.size(); i++) {
        int num = x * 10 + prime[i];
        if (!vis[num]) primes[num] = is_prime(num);
        if (primes[num]) solve(num, size + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (auto x : a) {
        solve(x, 1);
    }
}