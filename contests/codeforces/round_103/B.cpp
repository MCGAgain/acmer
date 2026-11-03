/**
 * Problem: CF 103B Cthulhu
 * Tags:
 *  //图论
 *  //并查集
 *  //连通性
 * Rating: 1700
 * Link: https://codeforces.com/problemset/problem/103/B
 */

#include <iostream>
using namespace std;

const int N = 110;

int n, m, p[N], cnt[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a == b) continue;
        p[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
    }
    int app = 0;
    for (int i = 1; i <= n; i++) if (cnt[i]) app++;
    if (n == m && app == 1) cout << "FHTAGN!" << '\n';
    else cout << "NO" << '\n';
}