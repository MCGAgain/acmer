#include <iostream>
#include <algorithm>
#include <array>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

#define Std
#ifdef Std
const int N = 2e5 + 10;
#endif
#ifdef Test
const int N = 2e1 + 10;
#endif

array<int, N> a, b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int x, y; cin >> x >> y;
    int coin = x, cash = y;

    repe(i, 1, n) cin >> a[i]; repe(i, 1, m) cin >> b[i];
    sort(a.begin() + 1, a.begin() + 1 + n); // 贪心排序，从最小的开始买
    sort(b.begin() + 1, b.begin() + 1 + m);
    repe(i, 1, n) a[i] += a[i - 1]; //前缀和处理，准备二分

    int ans = -1;
    repe(i, 0, m) { //逐个尝试drink买多少，去二分dessert买多少，实际是一种暴力的优化而已
        int cashCost = (b[i] + k - 1) / k;  
        if (cash - cashCost < 0) break; //判断cash够不够买i个drink，不够就结束
        cash -= cashCost;   
        coin += cashCost * k - b[i];
        int money = coin + cash * k;
        int l = 0, r = n;
        while (l < r) { //二分dessert买多少个
            int mid = (l + r + 1) / 2;
            if (a[mid] <= money) l = mid;
            else r = mid - 1;
        }
        int kinds = i + l;
        ans = max(kinds, ans);
    }

    cout << ans << '\n';
}

