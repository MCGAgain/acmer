#include <iostream>
typedef long long ll;
using namespace std;

const int N = 110;

int b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, c, cnt = 0; cin >> n >> m >> c;
    for (int i = 1; i <= m; i++) cin >> b[i];
    while (n--) {
        ll res = c;
        for (int i = 1; i <= m; i++) {
            int x; cin >> x;
            res += x * b[i];
        }
        if (res > 0) cnt++;
    }

    cout << cnt << '\n';
}