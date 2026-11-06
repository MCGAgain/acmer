#include <iostream>
#include <array>

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 5e5 + 10;

array<int, N> a, help;

int ans = 0;

void merge(int l, int m, int r) {
    int lp = l, rp = m + 1, ip = l;

    while (lp <= m && rp <= r) {
        if (a[lp] <= a[rp]) help[ip++] = a[lp++];
        else {
            ans += m - lp + 1;
            help[ip++] = a[rp++];
        }
    }
    while (lp <= m) help[ip++] = a[lp++];
    while (rp <= r) help[ip++] = a[rp++];
    for (int i = l; i <= r; i++) a[i] = help[i];
}

void count_rev(int l, int r) {
    if (l >= r) return;
    int m = l + r >> 1;
    count_rev(l, m);
    count_rev(m + 1, r);
    merge(l, m, r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    count_rev(0, n - 1);

    cout << ans << '\n';

}