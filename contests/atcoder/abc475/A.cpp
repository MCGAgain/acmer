#include <iostream>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    string ans;
    for (auto x : s) {
        ans += x;
        ans += 'o';
    }
    ans.pop_back();

    cout << ans << '\n';

}