#include <iostream>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b; cin >> a >> b;
    if (a == 1 || b == 1) cout << 1 << '\n';
    else cout << (a * b + 1LL) / 2LL << '\n';
}