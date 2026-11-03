/**
 * Problem: 码题集 二维前缀和
 * Tags:
 *  //基础算法
 *  //二维前缀和
 * Rating: 简单
 * Link: https://www.matiji.net/
 */

#include <iostream>
using namespace std;
#define int long long 
const int N = 110;

int gra[N][N];

int sub(int x1, int y1, int x2, int y2) {
   return gra[x2][y2] - gra[x1 - 1][y2] - gra[x2][y1 - 1] + gra[x1 - 1][y1 - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> gra[i][j];
            gra[i][j] += gra[i - 1][j] + gra[i][j - 1] - gra[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int x1 = 1; x1 <= n; x1 ++) 
        for (int y1 = 1; y1 <= m; y1++) 
            for (int x2 = x1; x2 <= n; x2 ++)
                for (int y2 = y1; y2 <= m; y2++) {
                    if (2 * sub(x1, y1, x2, y2) > (x2 - x1 + 1) * (y2 - y1 + 1)) ans++;
                }
    cout << ans << '\n';
}