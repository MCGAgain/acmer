/**
 * Problem: 1370A
 * Tags: 数论 
 * Rating: 800
 * Link: https://codeforces.com/problemset/problem/1370/A
 */

#include <iostream>
#include <bitset>
using namespace std;
#define S2

#ifdef S1
const int N = 1e6 + 10;

int prime[N], mf[N];
bitset<N> st;

void init() {
    int n = 1e6, cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            mf[i] = 1;
        }
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            st[prime[j] * i] = 1;
            mf[prime[j] * i] = i;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    int max_fac = -1;
    for (int i = 2; i <= n; i++) {
        if (mf[i] > max_fac) max_fac = mf[i];
        mf[i] = max_fac;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        cout << mf[x] << '\n';
    }
}
#endif

#ifdef S2

void solve() {
    int n; cin >> n;
    cout << n / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

#endif