#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b; cin >> a >> b;
    int cnt = 0, ans = 1;
    while (ans < b) {
        ans += a - 1;
        cnt++;
    };
    cout << cnt << '\n';
}