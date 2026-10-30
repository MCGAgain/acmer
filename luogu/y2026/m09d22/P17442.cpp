#include <iostream>
#include <array>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e5 + 10;
array<int, N> a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    repe(i, 1, n) cin >> a[i];

    int leftMax = -1, rightMax = -1;
    for (int l = 1, r = n; l <= n && r >= 1; l++, r--) {
        leftMax = max(leftMax, a[l]);
        rightMax = max(rightMax, a[r]);
        cout << max(leftMax, rightMax) << ' ';
    }
}