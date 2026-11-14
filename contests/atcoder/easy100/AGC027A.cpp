#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> a(n + 1, 0);

    rrep(i, 1, n) cin >> a[i];

    sort(a.begin() + 1, a.end());

    rrep(i, 1, n) a[i] += a[i - 1];

    int l = 0, r = n;

    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }

    if (a[l] < x && l == n) l--;

    cout << l << '\n';

}