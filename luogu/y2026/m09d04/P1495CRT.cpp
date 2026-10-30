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

const int N = 1e5 + 10;
int a[N], b[N];


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

    int n; cin >> n;

    int total = 1;
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        total = total * a[i];
    }

    for (int i = 1; i <= n; i++) {
        int m = total / a[i], x, y;

        exgcd(m, a[i], x, y);

        x = (x % a[i] + a[i]) % a[i];

        ans = (ans + ((__int128)b[i] * m * x) % total) % total;
    }

    cout << ans << '\n';

}