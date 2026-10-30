#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 5e4 + 10;
array<int, N> maxUp, maxDown;
int n, m, maxLen;

int lowbit(int i) {
    return i & -i;
}

void add(array<int, N> &T, int x, int len) {
    
    for (int i = x; i <= m; i += lowbit(i)) {
        if (T[i] < len) T[i] = len;
    }
}

int query(array<int, N> &T, int x) {
    maxLen = 0;
    for (int i = x; i; i -= lowbit(i)) {
        if (maxLen < T[i]) maxLen = T[i];
    }
    return maxLen;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector <int> a, b, h1, h2; a.push_back(0);
    int x; while (cin >> x) a.push_back(x);
    b = a; h1 = h2 = a;
    n = a.size() - 1;

    sort(h1.begin() + 1, h1.end());
    sort(h2.begin() + 1, h2.end(), greater<int>());

    h1.erase(unique(h1.begin() + 1, h1.end()), h1.end());
    h2.erase(unique(h2.begin() + 1, h2.end()), h2.end());
    m = h1.size() - 1;

    repe(i, 1, n) a[i] = lower_bound(h1.begin() + 1, h1.end(), a[i]) - h1.begin();
    repe(i, 1, n) b[i] = lower_bound(h2.begin() + 1, h2.end(), b[i], greater<int>()) - h2.begin();

    repe(i, 1, n) {
        query(maxUp, a[i] - 1);
        add(maxUp, a[i], maxLen + 1);

        query(maxDown, b[i]);
        add(maxDown, b[i], maxLen + 1);
    }

    cout << query(maxDown, m) << '\n' << query(maxUp, m) << '\n';

}//fdsjif