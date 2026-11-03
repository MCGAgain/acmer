#include <iostream>
#include <algorithm>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T; while (T--) {
        int a, b, c; cin >> a >> b >> c;
        int x0, y0;
        int d = exgcd(a, b, x0, y0);
        if (c % d) {
            cout << -1 << '\n';
            continue;
        }

        int dx = b / d, dy = a / d, mul = c / d;
        int x_minpos = (x0 % dx + dx) % dx * (mul % dx) % dx; // 先将 x0规范到 dx 内再扩大还原最后模到 dx
        if (x_minpos == 0) x_minpos += dx;  //正整数要求非零
        int y = (c - a * x_minpos) / b;
        if (y <= 0) {//x 的最小正整数解存在的前提下，y 的最大整数解仍然小于 0，说明正整数解不存在。
            int y_minpos = (y % dy + dy) % dy;
            if (y_minpos == 0) y_minpos += dy;
            cout << x_minpos << ' ' << y_minpos << '\n';
        }   
        else {  //正整数解存在
            int y_maxpos = y;
            int total = (y_maxpos - 1) / dy + 1;    //上整除，两种表达形式 (a + b - 1) / b, (a - 1) / b + 1;前者不会溢出
            int y_minpos = y_maxpos - (total - 1) * dy; //最小正整数解与最大正整数解相差 解的个数-1 个周期，利用周期直接做加法常数上比直接再规范 y 到最小正整数解更快
            int x_maxpos = x_minpos + (total - 1) * dx;
            //int y_minpos = (y_maxpos % dy + dy) % dy;
            //if (y_minpos == 0) y_minpos += dy;
            //int x_maxpos = (c - b * y) / a;

            cout << total << ' ' << x_minpos << ' ' << y_minpos << ' ' << x_maxpos << ' ' << y_maxpos << '\n';
        }
    }

}