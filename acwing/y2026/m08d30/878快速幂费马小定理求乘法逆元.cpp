#include <iostream>
using namespace std;
typedef long long ll;

ll qmi(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int a, p; cin >> a >> p;
        if (a % p) cout << qmi(a, p - 2, p) << '\n'; // 注意p = 2 特例指数为0直接返回1；
        else cout << "impossible" << '\n';
    }
}