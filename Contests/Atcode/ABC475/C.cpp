#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 1e4;

int a[N], p[N], n, s, L;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> L;

    int ans = -1;

    for (int i = 1; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) p[i + 1] = p[i] + a[i]; 

    for (int l = 1; l <= s; l++) {
        
        for (int r = s; r <= n; r++) {
            int x = p[s] - p[l], y = p[r] - p[s];
            if (min(2 * x + y, 2 * y + x) <= L) ans = (r - l + 1) > ans ? (r - l + 1) : ans;
        }
    }

    cout << ans << '\n';

}