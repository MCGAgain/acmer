#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

char p[N], s[M];
int n, m, ne[M];


void pre_next() {
    int i = 1, j = 0;
    while (i <= n) {
        if (!j || p[j] == p[i]) {
            i++, j++;
            ne[i] = j;
        }
        else j = ne[j];
    }
}

void kmp() {
    int i = 1, j = 1;
    while (i <= m) {
        if (!j || s[i] == p[j]) i++, j++;
        else j = ne[j];

        if (j > n) {
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