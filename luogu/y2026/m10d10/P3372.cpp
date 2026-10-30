#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e5 + 10;
int n, m;

array<int, N> a;
array<int, N << 2> sum, lazyinfo;

void lazy(int i, int v, int n) {
    sum[i] += v * n;
    lazyinfo[i] += v;
}

void up(int i) {
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void down(int i, int ln, int rn) {
    if (lazyinfo[i]) {
        lazy(i << 1, lazyinfo[i], ln);
        lazy(i << 1 | 1, lazyinfo[i], rn);
        lazyinfo[i] = 0;    //父节点清空！！！
    }
}

void build(int l, int r, int i) {
    if (l == r) sum[i] = a[l];
    else {
        int mid = (l + r) >> 1;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
    lazyinfo[i] = 0;
}

void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (jobl <= l && r <= jobr) {
        lazy(i, jobv, r - l + 1);
    }
    else {
        int mid = (l + r) >> 1;
        down(i, mid - l + 1, r - mid);
        if (jobl <= mid) {
            add(jobl, jobr, jobv, l, mid, i << 1);
        }
        if (jobr > mid) {
            add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1); 
        }
        up(i);
    }
}

int query(int jobl, int jobr, int l, int r, int i) {
    if (jobl <= l && r <= jobr) return sum[i];

    int mid = (l + r) >> 1, ans = 0;
    down(i, mid - l + 1, r - mid);
    if (jobl <= mid) {
        ans += query(jobl, jobr, l, mid, i << 1);
    }
    if (jobr > mid) {
        ans += query(jobl, jobr, mid + 1, r, i << 1 | 1);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    repe(i, 1, n) cin >> a[i];
    
    build(1, n, 1);
    
    while (m--) {
        int op; cin >> op;
        int l, r, v;
        if (op == 1) {
            cin >> l >> r >> v;
            add(l, r, v, 1, n, 1);
        }
        else {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << '\n';
        }
    }    

}