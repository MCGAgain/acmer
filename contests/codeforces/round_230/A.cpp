/**
 * Problem: CF 230A Dragons
 * Tags:
 *  //贪心
 *  //排序
 * Rating: 1000
 * Link: https://codeforces.com/problemset/problem/230/A
 */

#include <iostream>
#include <algorithm>
using namespace std;
#define int unsigned long long
const int N = 1e3 + 10; 

typedef struct {
    int f, v;
} item;

int s, n;
item a[N];

bool cmp(const item& a, const item& b) {
    return a.f < b.f;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> n;
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].v;
    sort(a, a + n, cmp);
    bool win = true;
    for (int i = 0; i < n; i++) {
        if (s <= a[i].f) {
            cout << "NO" << '\n';
            return 0;
        }
        s += a[i].v;
    }
    cout << "YES" << '\n';
}