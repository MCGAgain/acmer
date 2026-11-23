#include <iostream>
#include <bitset>

using namespace std;

const int N = 1e5 + 10;

int ne[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> ne[i];

    int cnt = 0;
    for (int i = 1;cnt < n; i = ne[i], cnt ++) {
        if (i == 2) {
            cout << cnt << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

}