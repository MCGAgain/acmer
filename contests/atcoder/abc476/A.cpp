#include <iostream>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    if (*s.rbegin() == 'e') cout << s + 'r' << '\n';
    else cout << s + "er" << '\n';
}