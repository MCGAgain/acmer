#include <iostream>
#include <map>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, int> a;
    rep(i, 1, n) {
        int x; cin >> x;
        a.insert({x, i});
    }

    for (auto [i, j] : a) cout << j << ' ';
    cout << '\n';
}