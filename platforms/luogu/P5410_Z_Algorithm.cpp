#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define int long long

using namespace std;

const int N = 2e7 + 10;

int z[N], e[N];
string s, p; 

void z_factor(int n) {

    z[0] = n;
    for (int i = 1, c = 1, r = 0, len; i < n; i++) {
        len = i < r ? min(z[i - c], r - i) : 0;

        while (i + len < n && p[i + len] == p [len]) len++;

        if (i + len > r) {
            c = i;
            r = i + len;
        }
        z[i] = len;
    }
}

void e_array(int n, int m) {
    
    for (int i = 0, c = 0, r = 0, len; i < n; i++) {
        len = i < r ? min(z[i - c], r - i) : 0;

        while (i + len < n && len < m && s[i + len] == p[len]) len++;

        if (i + len > r) {
            c = i;
            r = i + len;
        }

        e[i] = len;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> p;
    int n = s.size(), m = p.size();

    z_factor(m);

    e_array(n, m);

    int ans = 0;
    for (int i = 0; i < m; i++) ans ^= (i + 1) * (z[i] + 1);
    cout << ans << '\n';
    ans = 0;
    for (int i = 0; i < n; i++) ans ^= (i + 1) * (e[i] + 1);
    cout << ans << '\n';

}