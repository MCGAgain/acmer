#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define int long long 
typedef long long ll;
using namespace std;



int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}


void solve() {
   
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    bool has_ans = true;

    int n; cin >> n;

    int a1, m1; cin >> a1 >> m1;

    while (--n) {
        int a2, m2, k1, k2; cin >> a2 >> m2;

        int d = exgcd(a1, a2, k1, k2);

        if ((m2 - m1) % d) {
            has_ans = false;
            break;
        }

        k1 = (m2 - m1) / d * k1;
        int t = a2 / d; k1 = (k1 % t + t) % t;

        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);

    }

    if (has_ans) cout << (m1 % a1 + a1) % a1 << '\n';
    else cout << -1 << '\n';

}