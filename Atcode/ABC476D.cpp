#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2e5 + 10;

array<int, N> a, b;
int n, m, k, x, y;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k >> x >> y;

    repe(i, 1, n) cin >> a[i];
    repe(i, 1, m) cin >> b[i];

    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m);
    repe(i, 1, n) a[i] += a[i - 1];
    
    int ans = 0;
    repe(i, 0, m) {
        int cashCost = (b[i] + k - 1) / k;
        if (cashCost > y) break;
        y -= cashCost;
        x += cashCost * k - b[i];
        int l = 0, r = n, money = x + y * k;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= money) l = mid;
            else r = mid - 1;
        }

        int kind = i + l;
        ans = max(ans, kind);
    }

    cout << ans << '\n';

}