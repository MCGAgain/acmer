#include <iostream>
#include <algorithm>
#include <array>
#define endl '\n'
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 1e6 + 10;

struct section {
    int l, r, idx;
    bool operator<(const section &s) const {
        return this->r < s.r;
    }
} query[N];

int n, m;
array<int, N> tree, last_pos, a, ans;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) tree[i] += k;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tree[i];
    return res;
}

int range(int l, int r) {
    return sum(r) - sum(l - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rrep(i, 1, n) cin >> a[i];

    cin >> m;
    rrep(i, 1, m) {
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }

    sort(query + 1, query + 1 + m);

    int i = 1;  //单调扫描线
    rrep(r, 1, m) {
        auto sec = query[r];
        for (; i <= sec.r; i++) {
            if (last_pos[a[i]]) {
                add(last_pos[a[i]], -1);
            }
            add(i, 1);
            last_pos[a[i]] = i; 
        }

        ans[sec.idx] = range(sec.l, sec.r);
    }

    rrep(i, 1, m) cout << ans[i] << endl;
}