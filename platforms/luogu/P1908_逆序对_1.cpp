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
}

void count_rev(int l, int r) {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    

}