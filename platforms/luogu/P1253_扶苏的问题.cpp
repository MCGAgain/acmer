#include <iostream>
#include <array>
#include <algorithm>
#include <bitset>

#define repe(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 1e6 + 10;
int n, q;

array<int, N> a;
array<int, N << 2> lazyinfo, change, maxn;
bitset<N << 2> update;

void addLazy(int i, int v) {
    maxn[i] += v;
    lazyinfo[i] += v;
}

void updateLazy(int i, int v) {
    maxn[i] = v;
    lazyinfo[i] = 0;
    change[i] = v;
    update[i] = 1;
}

void up(int i) {
    maxn[i] = max(maxn[i << 1], maxn[i << 1 | 1]);
}

void down(int i) {
    if (update[i]) {
        updateLazy(i << 1, change[i]);
        updateLazy(i << 1 | 1, change[i]);
    }
    if (lazyinfo[i]) {
        addLazy(i << 1, lazyinfo[i]);
        addLazy(i << 1 | 1, lazyinfo[i]);
    }
    lazyinfo[i] = 0;
    change[i] = 0;
    update[i] = 0;
}

void build(int l, int r, int i) {
    if (l == r) maxn[i] = a[l];
    else {
        int mid = (l + r) >> 1;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
    lazyinfo[i] = 0;
    change[i] = 0;
    update[i] = 0;
}

void add(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (l >= jobl && r <= jobr) addLazy(i, jobv);
    else {
        int mid = (l + r) >> 1;
        down(i);
        if (jobl <= mid) add(jobl, jobr, jobv, l, mid, i << 1); 
        if (jobr > mid) add(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}

void reUpdate(int jobl, int jobr, int jobv, int l, int r, int i) {
    if (l >= jobl && r <= jobr) updateLazy(i, jobv);
    else {
        int mid = (l + r) >> 1;
        down(i);
        if (jobl <= mid) reUpdate(jobl, jobr, jobv, l, mid, i << 1); 
        if (jobr > mid) reUpdate(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }    
}

int query(int jobl, int jobr, int l, int r, int i) {
    if (l >= jobl && r <= jobr) return maxn[i];
    int mid = (l + r) >> 1, ans = -1e18;
    down(i);
    if (jobl <= mid) ans = max(ans, query(jobl, jobr, l, mid, i << 1));
    if (jobr > mid) ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    repe(i, 1, n) cin >> a[i];
    build(1, n, 1);
    
    while (q--) {
        int op; cin >> op;
        int l, r, x;

        if (op == 1) { //重置
            cin >> l >> r >> x;
            reUpdate(l, r, x, 1, n, 1);
        }
        else if (op == 2) { //加
            cin >> l >> r >> x;
            add(l, r, x, 1, n, 1);
        }
        else {
            cin >> l >> r;
            cout << query(l, r, 1, n, 1) << '\n';
        }
    }
}