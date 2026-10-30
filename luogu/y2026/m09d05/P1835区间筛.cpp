#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
#define int long long
using namespace std;

const int N = 7e4, M = 1e6 + 10;

int intSqrt(int x) {
    int res = 0;
    for (int i = 1 << 15; i > 0; i >>= 1) {
        int temp = res | i;
        if (temp <= x / temp) res = temp;
    }
    return res;
}

int getPrime(vector<int> &prime, int n) {
    bitset<N> st;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j]) break;
        }
    }

    return cnt;
}

void solve() {
    int l, r; cin >> l >> r;
    int n = intSqrt(r);

    vector<int> prime(n + 10);
    int cnt = getPrime(prime, n);

    bitset<M> st;

    for (int i = 0; i < cnt; i++) {
        int t = max(prime[i] * prime[i], (prime[i] + l - 1) / prime[i] * prime[i]);
        for (int j = t; j <= r; j += prime[i]) st[j - l] = 1;
    }

    int ans = 0;
    for (int i = 0; i <= r - l; i++) if (i + l >= 2 && !st[i]) ans++;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}