#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int a[N];
unordered_map<int, int> app;

void solve() {
    app.clear();
   int n; cin >> n;
   int c1, c2, c3, c4; c1 = c2 = c3 = c4 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        app[a[i]]++;
        if (a[i] & 1) c1++;
        if (a[i] % 4 == 2) c2++;
        if (a[i] % 4 == 0) c3++;
    }

    int maxc = -1;
    for (auto [a, b] : app) maxc = b > maxc ? b : maxc;
    c4 = maxc;

    cout << max(max(c1,c2), max(c3,c4)) << '\n';


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}