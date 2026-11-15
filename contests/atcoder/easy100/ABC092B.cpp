#include <iostream>
#define endl '\n'
using namespace std;

const int N = 110;

int f(int x, int d) {
    int cnt = 0, i = 0;
    while (i * x + 1 <= d) {
        cnt++; i++;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, x, a, ans = 0;
    cin >> n >> d >> x;

    for (int i = 0; i < n; i++) {
        cin >> a; ans += f(a, d);

    } 

    cout << ans + x << endl;
}