#include <iostream>
#include <algorithm>
using namespace std;

int map[30], max_char = 0;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    for (auto x : s) max_char = max(max_char, ++map[x - '0']);

    if (max_char == 1) cout << "yes" << '\n';
    else cout << "no" << '\n';

}