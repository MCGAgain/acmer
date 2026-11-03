/**
 * Problem: P1496 火烧赤壁
 * Tags:
 *  //基础算法
 *  //区间合并
 *  //离散化
 * Rating: 普及-
 * Link: https://www.luogu.com.cn/problem/P1496
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
typedef pair<int, int> PII;
int n;
/**
 * 区间合并
 */
void solve_1() {
    vector<PII> arr;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    int prel = -2e18, prer = -2e18, ans = 0;
    sort(arr.begin(), arr.end());
    for (auto [l, r] : arr) {
        if (prer < l) {
            ans += prer - prel;
            prel = l, prer = r;
        }
        else if (r > prer) prer = r;
    }
    ans += prer - prel;

    cout << ans << '\n';
}

/**
 * 离散化+差分
 */
vector<int> vidx;
int find(int x) {
    return lower_bound(vidx.begin(), vidx.end(), x) - vidx.begin() + 1;
}

void solve_2() {
    vector<int> a, b, s(2 * n + 10);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back(x); b.push_back(y);
        vidx.push_back(x); vidx.push_back(y);
    }
    sort(vidx.begin(), vidx.end());
    vidx.erase(unique(vidx.begin(), vidx.end()), vidx.end());

    for (int i = 0; i < a.size(); i++) {
        int l = find(a[i]), r = find(b[i]);
        s[l]++;
        s[r]--;
    }

    int ans = 0;
    for (int i = 1; i <= vidx.size(); i++) {
        s[i] += s[i - 1];
        if (s[i] > 0) ans += s[i] - s[i - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    //solve_1();
    solve_2();
}