#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

int a[110];

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int lp = 0, rp = n + 1;
    ll sum = 0;

    while (lp < rp - 1) {
        if (sum <= 0) sum += a[++lp];
        else sum -= a[--rp];
    }

    cout << abs(sum) << '\n';

}