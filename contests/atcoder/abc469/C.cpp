#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 1e6;

int idxs[N];
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') a[i + 1] = 1;
        else a[i + 1] = 0;
        a[i + 1] += a[i];
    }

    for (int k = 1; k <= n; k++) {
        int* begin = a + 1, *end = a + n + 2;
        int* p = lower_bound(begin, end, k);

        if (p == end) cout << n << '\n';

        else cout << (p - begin) + 1 << '\n';

    }
}