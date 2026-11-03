#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;

int n;
int phi[N], prime[N];
bitset<N> st;

ll get_euler() {
    int cnt = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i <= n / prime[j]; j++) {
            int t = prime[j] * i;
            st[t] = 1;
            if (i % prime[j] == 0) {
                phi[t] = phi[i] * prime[j];
                break;
            }
            phi[t] = phi[i] * (prime[j] - 1);
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cout << get_euler() << '\n';
}