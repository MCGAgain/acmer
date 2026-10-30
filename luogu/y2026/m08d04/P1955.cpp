/**
 * Problem: P1955 [NOI2015] 程序自动分析
 * Tags:
 *  //并查集
 *  //离散化
 *  //数据结构
 * Rating: 普及+/提高
 * Link: https://www.luogu.com.cn/problem/P1955
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
vector<PIII> query;
vector<int> vidx;
const int N = 2e5 + 10;
int p[N];
int cnt[N];
int f(int x) {
    return lower_bound(vidx.begin(), vidx.end(), x) - vidx.begin(); 
}
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool cmp(const PIII& a, const PIII& b) {
    return a.second > b.second;
}

void solve() {
    int n; cin >> n;
    query.clear();
    vidx.clear();
    memset(p, 0, sizeof p);
    memset(cnt, 0, sizeof cnt);
    
    for (int i = 0; i < n; i++) {
        int a, b, op; cin >> a >> b >> op;
        query.push_back({{a, b}, op});
        vidx.push_back(a), vidx.push_back(b);
    } 

    sort(vidx.begin(), vidx.end());
    vidx.erase(unique(vidx.begin(), vidx.end()), vidx.end());
    for (int i = 0;  i <= vidx.size(); i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    bool ans = true;
    sort(query.begin(), query.end(), cmp);

    for (auto [pa, op] : query) {
        auto [a, b] = pa;
        a = find(f(a)), b = find(f(b));
        if (op) {
            if (cnt[a] >= cnt[b]) {
                p[b] = a;
                cnt[a] += cnt[b];
                cnt[b] = 0;
            }
            else {
                p[a] = b;
                cnt[b] += cnt[a];
                cnt[a] = 0;
            }
        }
        else if (!op) {
            if (a == b) ans = false;
        }
    }

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
}