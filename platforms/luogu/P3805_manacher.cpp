#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int N = 1.1e7 + 10;
int n, p[N << 1];
string s;

char ss[N << 1];

void init() {
    n = s.size() * 2 + 1;
    for (int i = 0, j = 0; i < n; i++) {
        ss[i] = (i & 1) == 0 ? '#' : s[j++]; 
    }
}

int manacher() {
    int ans = 0;

    for (int i = 0, r = 0, c = 0, len; i < n; i++) {
        len = i < r ? min(p[2 * c - i], r - i) : 1;

        while (i + len < n && i - len >= 0 && ss[i - len] == ss[i + len]) len++;

        if (i + len > r) {
            c = i;
            r = i + len;
        }

        ans = max(ans, len);
        p[i] = len;
    }

    return ans - 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    init();

     cout << manacher() << '\n';
}