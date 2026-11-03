#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for (int i = (a); i < (b); i++) 
using namespace std;



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; vector<double>a(n); rep(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end());

    rep(i, 1, n) a[i] = (a[i] + a[i - 1]) / (double)2;

    cout << (double)a[n - 1] << '\n';

}