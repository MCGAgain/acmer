#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

unordered_map<string, int> st;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    while (n--) {
        
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 'a' - 'A';
        st[s]++;
    }

    int ans = -1;
    for (auto [a, b] : st) {
        ans = b > ans ? b : ans;
    }

    cout << ans << '\n';

}