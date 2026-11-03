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
        int a, k, p; cin >> a >> k >> p;
        cout << qmi(a, k, p) << '\n';
    }

}