#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <set>
#include <cstring>
#include <bitset>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
typedef long long ll;
using namespace std;

int intSqrt(int x) {
    int res = 0;

    for (int i = (1 << 30); i; i >>= 1) {
        int t = res | i;
        if (t <= x / t) res = t;
    }

    return res;
}

void solve() {
    int n; cin >> n;
    set<int> num;
    vector<int> ans, numQueue; ans.push_back(1);
    repe(i, 2, n) num.insert(i);

    while (num.size()) {
        
        int t = (*num.begin()); num.erase(t);
        int tempSum = ans.back() + t;
        int s = intSqrt(tempSum);

        while (s == tempSum / s) {
            numQueue.push_back(t);
            t = (*num.begin()); num.erase(t);
            tempSum = ans.back() + t;
            s = intSqrt(tempSum);
        }

        ans.push_back(t);
        while (numQueue.size()) {
            int tt = numQueue.back(); numQueue.pop_back();
            num.insert(tt);
        }

    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n'; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}