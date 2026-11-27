#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

const int N = 210;
string s;

int z[N];

int z_factor(int n) {
    int ans = 0;

    z[0] = n;
    for (int i = 1, c = 1, r = 0, len; i < n; i++) {
        len = i < r ? min(z[i - c], r - i) : 0;

        while (i + len < n && s[i + len] == s[len]) len++;

        if (i + len > r) {
            c = i;
            r = i + len;
        }

        if (i <= len) ans = max(ans, i * 2);
        z[i] = len;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int n = s.size();

    cout << z_factor(n - 1) << '\n';
}