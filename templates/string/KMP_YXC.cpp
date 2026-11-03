#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
int n, m, ne[M];

void pre_next() {
    int sl = 0;
    for (int i = 2; i <= n; i++) {
        while (sl && p[i] != p[sl + 1]) sl = ne[sl];
        if (p[i] == p[sl + 1]) sl++;
        ne[i] = sl;
    }
}

void kmp() {
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (p[j + 1] == s[i]) j++;

        if (j == n) {
            cout << i - j << ' ';
            j = ne[j];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p + 1 >> m >> s + 1;
    pre_next();
    kmp();
}