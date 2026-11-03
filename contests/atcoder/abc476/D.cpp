#include <iostream>
#include <algorithm>
#include <array>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

#define Std
#ifdef Std
const int N = 2e5 + 10;
#endif
#ifdef Test
const int N = 2e1 + 10;
#endif

array<int, N> a, b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;
    int coin = x, cash = y;

    repe(i, 1, n) cin >> a[i]; repe(i, 1, m) cin >> b[i];
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m);
    repe(i, 1, n) a[i] += a[i - 1];

    int ans = -1;
    repe(i, 0, m) {
        int cashCost = (b[i] + k - 1) / k;
        if (cash - cashCost < 0) break;
        cash -= cashCost;
        coin += cashCost * k - b[i];
        int money = coin + cash * k;
        auto end = a.begin() + 1 + n, begin = a.begin() + 1;
        auto it = lower_bound(begin, end, money);
        if (it == end) it--;
        else if (*it > money) it--;
        int kinds = i + (it - a.begin());
        ans = max(kinds, ans);
    }

    cout << ans << '\n';
}

