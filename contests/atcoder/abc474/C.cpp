#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;

int idx[N], a[2 * N], cnt = 0;

void move(int x) {
    if (idx[x] == cnt - 1) return;

    a[idx[x]] = 0; 
    idx[x] = cnt;
    a[cnt++] = x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[cnt++] = x;
        idx[x] = i;
    }

    while (q--) {
        int x; cin >> x;
        move(x);
    }

    for (int i = 0; i < cnt; i++) if (a[i]) cout << a[i] << ' ';
    cout << '\n';

}