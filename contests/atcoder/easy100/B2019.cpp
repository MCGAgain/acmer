#include <iostream>
using namespace std;

const int N = 5e4;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= N; i++) {
        if ((int)((double)i * 1.08) == n) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << ":(" << '\n';
}