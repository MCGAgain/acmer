#include <iostream>
#include <unordered_set>
#include <vector>
#define rep(i, a, b) for (int i = (a); i < (b); i++) 
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unordered_set<int> st = {'A', 'C', 'G', 'T'};

    string s; cin >> s;

    int ans = 0;
    rep(i, 0, s.size()) {
        if (!st.count(s[i])) continue;
        int len = 0;
        rep(j, i, s.size()) {
            if (!st.count(s[j])) break;
            len++;
        }
        ans = max(ans, len);
    }

    cout << ans << '\n';

}