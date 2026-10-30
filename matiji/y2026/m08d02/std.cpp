/**
 * Problem: 码题集 字符串平衡与双指针
 * Tags:
 *  //双指针
 *  //模拟
 *  //字符串
 * Rating: 简单
 * Link: https://www.matiji.net/
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<int> w(n + 10);

    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cnt_a++;
        else if (s[i] == 'c') s[i] = 'b';
    }

    cnt_b = n - cnt_a;
    s = ' ' + s;
    int l = 1, r = n;
    while (cnt_a != cnt_b) {
        if (s[l] == 'b') {
            l++;
            cnt_b--;
        }
        else if (cnt_a > cnt_b) {
            l++;
            cnt_a--;
        }
        else if (cnt_a < cnt_b) s[r--] == 'a' ? cnt_a-- : cnt_b--;
    }
    cout << l << ' ' << r << '\n';
}