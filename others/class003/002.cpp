#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 5005;
const ll MOD = 1000000007;

ll fac[MAXN];     // fac[i] 表示 i! % MOD
ll inv_fac[MAXN]; // inv_fac[i] 表示 (i!)^(-1) % MOD

// 快速幂：在 O(log b) 时间内计算 (a^b) % MOD
ll qpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘与阶乘逆元，总体时间复杂度 O(n)
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    // 先用快速幂求 n! 的逆元
    inv_fac[n] = qpow(fac[n], MOD - 2);

    // 再倒序线性递推出 0! 到 (n-1)! 的逆元
    for (int i = n - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

// O(1) 查询组合数 C(n, m) % MOD
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    // 分步取模防止三个 long long 相乘溢出
    return fac[n] * inv_fac[m] % MOD * inv_fac[n - m] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    init(n);
    cout << C(n, m) << "\n";

    return 0;
}
