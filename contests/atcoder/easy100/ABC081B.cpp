#include <iostream>
#include <algorithm>
using namespace std;

int CountFactor(int x) {
    int cnt = 0;
    while (!(x & 1)) {
        x >>= 1;
        cnt++;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int n; cin >> n;

    int ans = 2e9;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans = min(ans, CountFactor(x));
    }

    cout << ans << endl;

}