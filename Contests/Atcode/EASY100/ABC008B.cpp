#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 10), pe(3);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int p = 1;
    sort(a.rbegin(), a.rend());
    for (auto x : a) {
        pe[p] += x;
        p = 3 - p;
    }

    cout << pe[1] - pe[2] << '\n';

}