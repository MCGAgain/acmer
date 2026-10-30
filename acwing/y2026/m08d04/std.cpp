/**
 * Problem: AcWing 802. 区间和
 * Tags:
 *  //离散化
 *  //前缀和
 *  //二分
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/804/
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
int n, m;
vector<PII> query, add;
vector<int>  vidx;

auto find(int x) {
    return lower_bound(vidx.begin(), vidx.end(), x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        vidx.push_back(x);
        add.push_back({x, c});
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        vidx.push_back(l); vidx.push_back(r);
        query.push_back({l, r});
    }   

    sort(vidx.begin(), vidx.end());
    vidx.erase(unique(vidx.begin(), vidx.end()), vidx.end());

    vector<long long> s(vidx.size() + 10, 0); 
    for (int i = 0; i < n; i++) {
        int x = add[i].first, c = add[i].second;
        s[find(x) - vidx.begin() + 1] += c;
    }

    for (int i = 1; i <= vidx.size(); i++) {
        s[i] += s[i - 1];
    }
    
    for (int i = 0; i < m; i++) {
        int l = query[i].first, r = query[i].second;
        l = find(l) - vidx.begin() + 1; r = find(r) - vidx.begin() + 1;
        cout << s[r] - s[l - 1] << '\n';
    }
}
