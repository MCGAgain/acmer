/**
 * Problem: CF 1108B Divisors of Two Numbers
 * Tags:
 *  //数论
 *  //贪心
 *  //约数
 * Rating: 1000
 * Link: https://codeforces.com/problemset/problem/1108/B
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 150;
map<int, int> divs;

vector<int> get_divisor(int x) {
    vector<int> res;
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
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        divs[x]++;
    }
    cout << divs.rbegin()->first << ' ';
    for (auto d : get_divisor(divs.rbegin()->first)) divs[d]--;
    for (auto i = divs.rbegin(); i != divs.rend(); i++) 
        if (i->second > 0) {
            cout << i->first << ' ';
            break;
        }
}