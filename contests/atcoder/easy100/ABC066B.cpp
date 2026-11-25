#include <iostream>
#include <algorithm>
using namespace std;


#if 1
string s; 

bool same(int l, int m) {
    int r = m + 1;
    while (l <= m) {
        if (s[l] != s[r]) return false;
        l++, r++;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s = ' ' + s;

    int ans = 0;
    for (int i = 2; i < s.size() - 1; i += 2) {
        if (same(1, i + 1 >> 1)) 
            ans = max(ans, i);
    }

    cout << ans << '\n';
}
#endif
