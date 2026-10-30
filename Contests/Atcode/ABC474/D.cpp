#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;
const ll M = 1e18;


int a[N], b[N];

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool tag = false;
    for (int i = 0; i < n; i++) if (a[i] > b[i]) tag = true;

    if (!tag) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes" << '\n';

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) cout << M << ' ';
        else cout << 1 << ' ';
    }
    cout << '\n';
}