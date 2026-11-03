#include <iostream>
#include <unordered_set>
#define rep(i, a, b) for (int i = (a); i < (b); i++) 
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, k; cin >> x >> k;

    cout << min(x % k, abs(x % k - k)) << '\n';

}