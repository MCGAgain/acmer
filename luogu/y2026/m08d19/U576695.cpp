/**
 * Problem: U576695 试除法求约数
 * Tags:
 *  //数论
 *  //试除法
 *  //约数
 * Rating: 暂无评定
 * Link: https://www.luogu.com.cn/problem/U576695
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisor(int x) {
    vector<int> res;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        auto ans = get_divisor(x);
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}