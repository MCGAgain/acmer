#include <iostream>
#include <algorithm>
#define int long long
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int N = 2e5 + 10, M = 2e5 + 10;

int a[N], b[M];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;

    rrep(i, 1, n) cin >> a[i];
    rrep(i, 1, m) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    rrep(i, 1, n) a[i] += a[i - 1];

    int ans = 0;

    rrep(i, 0, m) {
        int cost = (b[i] + k - 1) / k;
        if (cost > y) break;
        y -= cost;
        x += cost * k - b[i];
        int sum = x + y * k;

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= sum) l = mid;
            else r = mid - 1;
        }

        ans = max(ans, i + l);
    }

    cout << ans << '\n';
}