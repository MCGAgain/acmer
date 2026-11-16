#include <iostream>
using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

// C[i][j] 存储组合数 C(i, j) % MOD
int C[MAXN][MAXN];

int main() {
    // 优化标准输入输出流速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1. 初始化边界：从 0 个物品中选 0 个，方案数为 1
    C[0][0] = 1;

    // 2. 逐行递推计算杨辉三角，时间复杂度 O(n^2)
    for (int i = 1; i <= n; i++) {
        // 每行的第 0 列（选 0 个）恒为 1
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            // 状态转移：不选第 i 个 + 选第 i 个
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    cout << C[n][m] << "\n";
    return 0;
}
