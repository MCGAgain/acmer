#include <iostream>
#include <cmath>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int tag = 753, ans = 1e9;

    for (int i = 0; i + 2 < s.length(); i++) {

        int t = stoi(s.substr(i, 3));
        ans = min(ans, abs(t - tag));
    }

    cout << ans << '\n';
}