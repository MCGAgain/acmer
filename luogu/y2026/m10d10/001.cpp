#include <iostream>
#include <array>
#include <bitset>
#include <random>
#include <chrono>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1010;

array<int, N> a, checkA;
array<int, N << 2> sum, change;
bitset<N << 2> update;

void lazy(int i, int v, int n) {
    sum[i] = v * n;
    change[i] = v;
    update[i] = 1;
}

void up(int i) {
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void down(int i, int ln, int rn) {
    if (update[i]) {
        lazy(i << 1, change[i], ln);
        lazy(i << 1 | 1, change[i], rn);
        update[i] = 0;
    }
}

void reUpdate(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (l >= jobl && r <= jobr) lazy(i, jobv, r - l + 1);
    else {
        int mid = l + r >> 1;
        down(i, mid - l + 1, r - mid);
        if (jobl <= mid) reUpdate(jobl, jobr, jobv, l, mid, i << 1);
        if (jobr > mid) reUpdate(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}

int query(int jobl, int jobr, int l, int r, int i) {
    if (l >= jobl && r <= jobr) return sum[i];
    int mid = l + r >> 1, ans = 0;
    down(i, mid - l + 1, r - mid);
    if (jobl <= mid) ans += query(jobl, jobr, l, mid, i << 1);
    if (jobr > mid) ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
    return ans;
}

void bruteReUpdate (int jobl, int jobr, int jobv) {
    repe(i, jobl, jobr) checkA[i] = jobv;
}

int bruteQuery (int jobl, int jobr) {
    int ans = 0;
    repe(i, jobl, jobr) ans += checkA[i];
    return ans;
}

void build(int l, int r, int i) {
    if (l == r) sum[i] = a[l];
    else {
        int mid = l + r >> 1;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
    update[i] = 0;
    change[i] = 0;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int NR = 1000, V = 2000, T = 5000000;

int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void randomArray(int n) {
    repe(i, 1, n) a[i] = get_rand(1, V);
    repe(i, 1, n) checkA[i] = a[i];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v, t;
    n = get_rand(1, NR);
    t = get_rand(1, T);
    randomArray(n);
    build(1, n, 1);

    cout << "Start" << '\n';
    while (t--) {
        int op = get_rand(0, 1);
        int l = get_rand(1, n), r = get_rand(l, n), v = get_rand(1, V);
        if (op == 1) {
            reUpdate(l, r, v, 1, n, 1);
            bruteReUpdate(l, r, v);
        }
        else {
            if (query(l, r, 1, n, 1) != bruteQuery(l, r)) cout << "Wrong Answer..." << '\n';
        }
    }
    cout << "End" << '\n';
}