#include <iostream>
#include <array>
#define rep(i, a, b) for (int i = (a); i < (b); i++) 
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int M = 1e5 + 10, N = 1e6 + 10;

char p[M], s[N];
int ne[M], n, m;

void pre_next() {
    // if (m == 1) {
    //     ne[0] = -1; return;
    // }
    ne[0] = -1; ne[1] = 0;
    for (int i = 2, cn = 0; i <= m;) {
        if (p[i - 1] == p[cn]) ne[i++] = ++cn; // 根据next的两维定义，1.最大等长前后缀长度，2.主串中下一次开始匹配的下标，那么有此时有i - 1 = cn， 则ne[i] = cn + 1;
        else if (cn > 0) cn = ne[cn];
        else ne[i++] = 0;
    }
}

void kmp() {
    for (int x = 0, y = 0; x < n;) {
        if (s[x] == p[y]) {
            x++;
            y++;
        }
        else if (y == 0) x++;
        else y = ne[y];

        if (y == m) {
            cout << x - y << ' ';
            y = ne[y];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> p >> n >> s;

    pre_next();
    kmp();
}