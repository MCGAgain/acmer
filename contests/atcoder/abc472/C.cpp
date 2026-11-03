#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
#define int long long
using namespace std;

const int N = 2e5 + 10;

int a[N];

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    queue<signed> counted;

    int n, m, k; cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    int len = 0, sum = 0; // i - k + 1
    for (int i = 1; i <= n; i++) {
        int j = i - m + 1;
        if (j > 1 && (j - 1) == counted.front()) {
            sum -= a[counted.front()];
            counted.pop();
        }

        if (sum + a[i] <= k) {
            cout << "Yes" << '\n';
            sum += a[i];
            counted.push(i);
        }
        else {
            cout << "No" << '\n';
        }
        
    }

}