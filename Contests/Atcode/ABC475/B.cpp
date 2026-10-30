#include <iostream>
typedef long long ll;
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    ll c1 = 0, c10 = 0, c100 = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x = (x + 999) / 1000 * 1000 - x;
        c100 += (x / 100) % 10;
        c10 += (x / 10) % 10;
        c1 += x % 10;
    }

    cout << c1 << ' ' << c10 << ' ' << c100 << '\n';

}