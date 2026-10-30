#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

int a[110], n;

ll sum(int p) {
    ll res = 0;
    for (int i = 1; i <= n; i++) res += (a[i] - p) * (a[i] - p);
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll cost = 1e18;

    for (int i = 1; i <= 100; i++) {
        ll t = sum(i);
        if (t < cost) {
            cost = t;
        }
    } 

    cout << cost << '\n';

}