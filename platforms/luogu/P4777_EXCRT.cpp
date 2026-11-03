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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a1, b1; cin >> n >> a1 >> b1;

    while (--n) {
        int a2, b2, k1, k2; cin >> a2 >> b2;

        int d = exgcd(a1, a2, k1, k2);

        __int128 temp = (__int128)(b2 - b1) / d * k1;    //倍数放缩
        int t = a2 / d;
        k1 = (__int128)(temp % t + t) % t;

        b1 = a1 * k1 + b1; 
        a1 = abs(a1 / d * a2);
    }

    cout << (b1 % a1 + a1) % a1 << '\n';
}