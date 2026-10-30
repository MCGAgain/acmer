/*
未优化
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i, a, b) for (int i = (a); i <= (b); i++) 

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; vector<int> a(n + 10); //Q 为什么开n要re？？？？
    rep(i, 1, n) cin >> a[i];

    multiset<int> q;
    rep(i, 1, n) {
        q.insert(a[i]);
        if (i >= 3) {
            auto it = q.rbegin();
            rep(j, 1, 2) it++;
            cout << *it << '\n';
        } 
    }
}