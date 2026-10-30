#include <iostream>
#define int long long
using namespace std;

int stoll(string& s) {
    int res = 0;
    for (auto x : s) res = res * 10 + (x - '0');

    return res;
}

int intSqrt(int x) {
    int res = 0;
    for (int i = (1LL << 62); i; i >>= 1) {
        int t = res | i;
        if (t <= x / t) res = t;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    a = a + b;
    int x = stoll(a);
    int sx = intSqrt(x);
    if (x == sx * sx) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}