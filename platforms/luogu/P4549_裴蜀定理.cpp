#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ans = 0, n;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        ans = gcd(ans, abs(x));
    }
    cout << ans << '\n';
}