#include <iostream>
#include <vector>
#include <algorithm>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int N = 1e5 + 10;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; repe(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);

    cout << a[n / 2 + 1] - a[n / 2] << '\n';
}