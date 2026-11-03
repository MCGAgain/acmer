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
unordered_map<int, int> st;

void solve() {
    st.clear();
    int n; cin >> n;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        st[x]++;
        if (x & 1) c1++;
        else if (x % 4 == 0) c2++;
        else if (x % 4 == 2) c3++;
    }
    int maxc = -1;
    for (auto [a, b] : st) maxc = b > maxc ? maxc : b;
    c4 = maxc;

    cout << max(max(c1, c2), max(c3, c4)) << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}