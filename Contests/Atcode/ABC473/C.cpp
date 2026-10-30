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
unordered_map<int, int> cls;

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cls[x]++;
    }

    int max = -1;
    for (auto [a, b] : cls) max = b > max ? b : max;

    ll ans = 0;
    for (auto [a, b] : cls) if (b == max || b == (max - 1)) ans++;

    cout << ans << '\n';

}