#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

// dp[j] 在第 i 轮外层循环结束后，表示组合数 C(i, j) % MOD
int dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1. 初始化边界：C(0, 0) = 1，且后续所有轮次的 C(i, 0) 均复用此值
    dp[0] = 1;

    // 2. 外层枚举物品总数 i，时间复杂度 O(n * m)
    for (int i = 1; i <= n; i++) {
        // 3. 内层逆序枚举选出的个数 j（类似 0/1 背包的空间压缩）
        // 剪枝：超过 m 的列对最终答案 dp[m] 无影响，直接从 min(i, m) 开始
        for (int j = min(i, m); j >= 1; j--) {
            // 此时 dp[j] 是上一轮的 C(i-1, j)，dp[j-1] 是上一轮的 C(i-1, j-1)
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }

    cout << dp[m] << "\n";
    return 0;
}
