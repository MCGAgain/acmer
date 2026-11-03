#include <iostream>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        if (t[i] != '*' && t[i] != s[i]) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
}