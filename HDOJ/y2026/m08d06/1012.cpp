/**
 * Problem: HDU 1012 u Calculate e
 * Tags:
 *  //基础语法
 *  //模拟
 * Rating: 入门
 * Link: https://acm.hdu.edu.cn/showproblem.php?pid=1012
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int p[N], n;
ll w[N];

void solve_1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        p[i] = i;
    }

    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        p[i] = x;
    }

    __int128_t s = 0, delt = 0, ans;
    for (int i = 2; i <= n; i++) if (p[i] == 1) s += w[i];
    for (int i = 2; i <= n; i++) delt += w[i];

    ans = s + delt;

    if (ans == 0) cout << 0 << '\n';
    else if (ans < 0) cout << -1 << '\n';
    else cout << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve_1();
}