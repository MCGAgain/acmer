#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

int cnt[200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    int maxColor = -1;

    for (int i = 1; i <= n; i++) {
        maxColor = maxColor > cnt[i] ? maxColor : cnt[i];
    }

    if (n) cout << n - maxColor << '\n';
    else cout << 0 << '\n';

}