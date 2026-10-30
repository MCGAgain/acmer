#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define int long long 

typedef long long ll;

using namespace std;



int solve(int n) {
    int res = 0;

    for (int i = 1; i <= n;) {
        int d = n / i;
        int r = min(n / d, n);
        res += d * (r - i + 1);

        i = r + 1;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    cout << solve(N) << '\n';
}