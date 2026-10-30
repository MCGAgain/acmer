// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int Sum(int d, int L, int R) {
//     int res = 0;
//     for (int l = L; l <= R; ) {
//         int r = (d / l == 0) ? R : min(R, d / (d / l));
//         res += (d / l) * (l + r) * (r - l + 1) / 2;
//         l = r + 1;
//     }
//     return res;
// }

// void solve() {
//     int x, y, k;
//     cin >> x >> y >> k;
//     int d = y - x;

//     int p1 = (x + x + k) * (k + 1) / 2;
//     int p2 = Sum(d, x, x + k);

//     cout << p1 + p2 << "\n";
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int T; cin >> T;
//     while (T--) solve();
// }

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

int x, y, k;

int Sum(int l, int r) {
    return (l + r) * (r - l + 1)  / 2;
}

void solve() {
    int res = 0;
    cin >> x >> y >> k;
    int D = y - x;
    res += k * D;
    int L = x, R = min(D, x + k - 1);
    for (int l = L; l <= R; ) {
        int d = D / l;
        int r = min(R, D / d);
        res -= d * Sum(l, r);
        l = r + 1;
    }

    cout << res << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve(); 

}
