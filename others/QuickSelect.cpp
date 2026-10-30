#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

const int N = 1e5 + 10;
int a[N];

int quick_select(int l, int r, int k) {
    if (l == r) return a[l];
    int tag = a[l + r >> 1], i = l - 1, j = r + 1;

    while (i < j) {
        while (a[++i] < tag);
        while (a[--j] > tag);
        if (i < j) swap(a[i], a[j]);
    }

    int t = tag - l + 1; // 左区间元素个数，无关起始 0 还是 1
    if (k <= t) quick_select(l, j, k);
    else quick_select(j + 1, r, k - t); //k 属于右区间的第 k - 个，递归处理
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    cout << quick_select(0, n - 1, k) << '\n';
}