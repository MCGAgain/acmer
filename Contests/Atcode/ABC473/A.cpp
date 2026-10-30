#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 200;
int a[N];


void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for (int i = n / 2; i < n; i++) sum += a[i];

    cout << sum << '\n';

}