#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 30;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    bitset<N> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') st[i / k] = 1;
    }
    for (int i = 0; i < n / k; i++) {
        if (!st[i]) cnt++;
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}