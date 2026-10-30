#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2e3 + 10;

array<int, N> maxLenTree, maxLenCntTree;
int n, maxLen = 0, maxCnt = 0, m;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int len, int cnt) {
    
    for (int i = x; i <= m; i += lowbit(i)) {
        if (len == maxLenTree[i]) maxLenCntTree[i] += cnt;
        else if (len > maxLenTree[i]) {
            maxLenTree[i] = len;
            maxLenCntTree[i] = cnt;
        }
    }
}

void query(int x) {
    maxLen = maxCnt = 0;

    for (int i = x; i; i -= lowbit(i)) {
        if (maxLen == maxLenTree[i]) maxCnt += maxLenCntTree[i];
        else if (maxLen < maxLenTree[i]) {
            maxLen = maxLenTree[i];
            maxCnt = maxLenCntTree[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; vector <int> a(n + 1), help;
    repe(i, 1, n) cin >> a[i];

    help = a; sort(help.begin() + 1, help.end());

    help.erase(unique(help.begin() + 1, help.end()), help.end());
    m = help.end() - help.begin() - 1;
    repe(i, 1, n) a[i] = lower_bound(help.begin() + 1, help.end(), a[i]) - help.begin();

    repe(i, 1, n) {
        query(a[i] - 1);
        add(a[i], maxLen + 1, max(1, maxCnt));
    }

    query(m); cout << maxCnt << '\n';
}
