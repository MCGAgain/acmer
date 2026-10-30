#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;



void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    vector <int> L, R;
    
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < 0) L.push_back(x);
        else R.push_back(x);
    }

    sort(L.begin(), L.end());
    sort(R.rbegin(), R.rend());


    ll ans = 0;
    int l, r, x = 0;

    while (L.size() && R.size()) {
        l = L.back(), r = R.back();
        if (r - x < x - l) {
            ans += r - x;
            R.pop_back();
            x = r;
        }
        else {
            ans += x - l;
            L.pop_back();
            x = l;
        }
    }

    while (L.size()) {
        l = L.back(); L.pop_back();
        ans += x - l; x = l;
    }

    while (R.size()) {
        r = R.back(); R.pop_back();
        ans += r - x; x = r;
    }

    cout << ans << '\n';

}