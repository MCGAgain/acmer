#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int n = 6;
int a[100], help[100], cnt = 0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void merge(int l, int m, int r) {
    int i = l,/*i 从 l 开始方便在拷贝的时候规避下标映射*/ lp = l, rp = m + 1;
    while (lp <= m && rp <= r) {
        if (a[lp] <= a[rp]) help[i++] = a[lp++];
        else {
            cnt += m - lp + 1;
            help[i++] = a[rp++];
        }
    }
    while (lp <= m) help[i++] = a[lp++];
    while (rp <= r) help[i++] = a[rp++];
    for (int j = l; j <= r; j++) a[j] = help[j];
}

void qsort(int l, int r) {
    if (l >= r) return;
    int m = l + r >> 1;
    qsort(l, m);
    qsort(m + 1, r);
    merge(l, m, r);
}

int rngArray(int n) {
    if (n > 100) return -1;

    for (int i = 0; i < n; i++) a[i] = rng() % 100;
    return 0;
}


signed main() {

    rngArray(n);
    rep(i, 0, n) cout << a[i] << ' ';
    cout << '\n';

    qsort(0, n - 1);

    rep(i, 0, n) cout << a[i] << ' ';
    cout << '\n';

    cout << cnt << '\n';

}