/**
 * Problem: P5736 【深基7.例2】质数筛
 * Tags:
 *  //语法基础
 *  //试除法
 *  //质数判定
 * Rating: 入门
 * Link: https://www.luogu.com.cn/problem/P5736
 */

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= n / i; i++) if (x % i == 0) return false;
    return true;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) if (is_prime(a[i])) cout << a[i] << ' ';
}