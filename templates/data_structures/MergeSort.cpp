#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int a[100], help[100];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void rngArray(int n) {
    for (int i = 0; i < n; i++) a[i] = rng() % 100;
}

void merge(int l, int m, int r) {
    int i = l;
    int lp = l, rp = m + 1;
    while (lp <= m && rp <= r) help[i++] = a[lp] <= a[rp] ? a[lp++] : a[rp++];
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


signed main() {

    int n = 20;
    rngArray(n);
    rep(i, 0, n) cout << a[i] << ' ';
    cout << '\n';

    qsort(0, n - 1);

    rep(i, 0, n) cout << a[i] << ' ';
    cout << '\n';

}