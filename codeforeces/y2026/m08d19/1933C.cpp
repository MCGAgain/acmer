/**
 * Problem: CF 1933C Turtle Fingers: Count the Values of k
 * Tags:
 *  //数论
 *  //约数枚举
 *  //暴力
 * Rating: 1100
 * Link: https://codeforces.com/problemset/problem/1933/C
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<int> st;

vector<int> get_divisor(int x) {
    vector <int> res;

    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) res.push_back(x / i); 
        }
    }

    return res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        st.clear();
        int a, b, x; cin >> a >> b >> x;
        auto div = get_divisor(x);
        int ans = 1;
        for (int i = 1; i <= x; i *= a) 
            for (int j = 1, t; (t = j * i) <= x; j *= b) {
                if (x % t == 0) st.insert(x / t);
            }
        cout << st.size() << '\n';
    }
}