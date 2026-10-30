#include <iostream>

using namespace std;

// 扩展欧几里得算法：求解 a*x + b*y = gcd(a, b)
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long x0, y0;
    long long d = exgcd(a, b, x0, y0);

    // 1. 裴蜀定理判定无解
    if (c % d != 0) {
        cout << -1 << "\n";
        return;
    }

    // 2. 步长与特解计算
    long long dx = b / d;
    long long dy = a / d;
    long long mul = c / d;

    // 使用 __int128 防止 x0 * mul 接近或超过 long long 上限
    __int128 x_large = (__int128)x0 * mul;
    
    // 3. 将 x 规范化到最小正整数 [1, dx]
    long long x_min = (x_large % dx + dx) % dx;
    if (x_min == 0) x_min += dx;

    // 4. 反代求出此时对应的 y（此时的 y 一定是所有正整数 x 中对应的最大整数 y）
    long long y = (c - a * x_min) / b;

    if (y <= 0) {
        // 无正整数解：输出 x 的最小正整数解，以及 y 的最小正整数解
        long long y_large = (__int128)y0 * mul;
        long long y_min_pos = (y_large % dy + dy) % dy;
        if (y_min_pos == 0) y_min_pos += dy;

        cout << x_min << " " << y_min_pos << "\n";
    } else {
        // 存在正整数解
        long long y_max = y;
        // 统计正整数解组数：y 从 y_max 开始每次减少 dy，直到保持 >= 1
        long long total = (y_max - 1) / dy + 1;

        // 求 y 的最小正整数解
        long long y_min = (y_max % dy + dy) % dy;
        if (y_min == 0) y_min += dy;

        // 当 y 取最小值 y_min 时，x 达到最大正整数解
        long long x_max = (c - b * y_min) / a;

        cout << total << " " 
             << x_min << " " 
             << y_min << " " 
             << x_max << " " 
             << y_max << "\n";
    }
}

int main() {
    // 针对 T = 2e5 级别输入的极速 IO 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
