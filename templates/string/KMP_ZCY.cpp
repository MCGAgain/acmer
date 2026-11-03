#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
char p[N], s[M];
int ne[N];

void pre_next() {
    ne[0] = -1;
    for (int i = 2, cn = 0; i <= n;) {
        if (p[i - 1] == p[cn]) ne[i++] = ++cn;
        else if (!cn) ne[i++] = 0;
        else cn = ne[cn];
    }
}

void kmp() {
    for (int i = 0, j = 0; i < m;) {
        if (s[i] == p[j]) i++, j++;
        else if (!j) i++;
        else j = ne[j];

        if (j == n) {
            cout << i - j << ' ';
            j = ne[j];
        }
    } 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> m >> s;
    pre_next();
    kmp();
}