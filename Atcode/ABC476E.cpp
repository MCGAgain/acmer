#include <iostream>
#include <algorithm>
#include <array>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 2e5 + 10;
int n, m;

struct Node {
    int mn, mnPos, mx, mxPos;
};

array<int, N> a;
array<Node, N << 2> segTree;

Node merge(const Node& l, const Node& r) {
    Node res;
    if (l.mn < r.mn) {
        res.mn = l.mn;
        res.mnPos = l.mnPos;
    }
    else {
        res.mn = r.mn;
        res.mnPos = r.mnPos;
    }
    if (l.mx > r.mx) {
        res.mx = l.mx;
        res.mxPos = l.mxPos;
    }
    else {
        res.mx = r.mx;
        res.mxPos = r.mxPos;
    }
    return res;
}

void up(int i) {
    segTree[i] = merge(segTree[i << 1], segTree[i << 1 | 1]);
}

void build(int l, int r, int i) {
    if (l == r) segTree[i] = {a[l], l, a[l], l};
    else {
        int mid = (l + r) >> 1;
        build(l, mid, i << 1);
        build(mid + 1, r, i << 1 | 1);
        up(i);
    }
}

void update(int jobi, int jobv, int l, int r, int i) {
    if (l == r) segTree[i] = {jobv, jobi, jobv ,jobi};
    else {
        int mid = (l + r) >> 1;
        if (jobi <= mid) update(jobi, jobv, l, mid, i << 1);
        else update(jobi, jobv, mid + 1, r, i << 1 | 1);
        up(i);
    }
}

Node query(int jobl, int jobr, int l, int r, int i) {
    if (l >= jobl && r <= jobr) return segTree[i];
    int mid = (l + r) >> 1;

    if (jobr <= mid) return query(jobl, jobr, l, mid, i << 1);
    if (jobl > mid) return query(jobl, jobr, mid + 1, r, i << 1 | 1);
    return merge(query(jobl, jobr, l, mid, i << 1), query(jobl, jobr, mid + 1, r, i << 1 | 1));

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    repe(i, 1, n) cin >> a[i];
    build(1, n, 1);
    while (m--) {
        int l, r; cin >> l >> r;
        Node t = query(l, r, 1, n, 1);
        update(t.mnPos, t.mx, 1, n, 1);
        update(t.mxPos, t.mn, 1, n, 1);
        swap(a[t.mnPos], a[t.mxPos]);
    }
    repe(i, 1, n) cout << a[i] << ' ';
    cout << '\n';
}