#include <iostream>
#include <array>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2100;
array<array<int, N>, N> info1, info2, info3, info4;
int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int y, int v) {
    int v1 = v, v2 = v * x, v3 = v * y, v4 = v * x * y;
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j)) {
            info1[i][j] += v1;
            info2[i][j] += v2;
            info3[i][j] += v3;
            info4[i][j] += v4;
        }
}

void add(int a, int b, int c, int d, int v) {
    add(a, b, v);
    add(c + 1, b, -v);
    add(a, d + 1, -v);
    add(c + 1, d + 1, v);
} 

int sum (int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            ans += (x + 1) * (y + 1) * info1[i][j] - (x + 1) * info3[i][j] - (y + 1) * info2[i][j] + info4[i][j];
    return ans;
}

int range(int a, int b, int c, int d) {
    return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c, d, x;
    char op;

    while (cin >> op) {
        cin.ignore();
        if (op == 'X') cin >> n >> m;
        else if (op == 'L') {
            cin >> a >> b >> c >> d >> x;
            add(a, b, c, d, x);
        }
        else {
            cin >> a >> b >> c >> d;
            cout << range(a, b, c, d) << '\n'; 
        }
    }
}
