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

int s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    unordered_map<signed, signed> prePos;

    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        (s[i] += s[i - 1]) %= k;
    }

    int lastTailPos = 0, ans = 0;
    prePos[0] = 0;

    for (int i = 1; i <= n; i++) {
        int curV = s[i];
        if (prePos.count(curV) && lastTailPos <= prePos[curV]) {
            ans++;
            lastTailPos = i;
        }
        prePos[curV] = i;
    }

    cout << ans << '\n';

}