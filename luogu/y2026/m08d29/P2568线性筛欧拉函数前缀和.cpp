#include <iostream>
#include <bitset>
#define int long long
using namespace std;
typedef long long ll;

const int N = 1e7 + 10;
int prime[N], sphi[N];
bitset<N> st;

ll get_euler(int n) {
    int cnt = 0;

    sphi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            sphi[i] = i - 1;
        }
        for (int j = 0; j < cnt && prime[j] <= n / i; j++) {
            int t = prime[j] * i; st[t] = 1;
            if (i % prime[j] == 0) {
                sphi[t] = sphi[i] * prime[j];
                break;
            }
            sphi[t] = sphi[i] * (prime[j] - 1);
        }
    }

    for (int i = 1; i <= n; i++) sphi[i] += sphi[i - 1];

    ll res = 0;
    for (int i = 0;  i < cnt; i++) {
        res = res + 2 * sphi[n / prime[i]] - 1;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << get_euler(n) << '\n';
}