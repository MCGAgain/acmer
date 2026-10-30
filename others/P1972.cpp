#include <iostream>
#include <array>
#include <algorithm>
#define  int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

struct info {
    int l, r, idx;

    bool operator<(const info o) const {
        return this->r < o.r;
    }
};

const int N = 1e6 + 10;
int n, q;
array<int, N> last_pos, tree, a, ans;
array<info, N> query;

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

int qry(int l, int r) {
    return sum(r) - sum(l - 1);
}


signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; rrep(i, 1, n) cin >> a[i];
    cin >> q;
    rep(i, 0, q) {
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    sort(query.begin(), query.begin() + q);

    int j = 1;
    rep(i, 0, q) {

        for (; j <= query[i].r; j++) {
            int color = a[j];
            if (last_pos[color]) {
                add(last_pos[color], -1);
            }

            add(j, 1);
            last_pos[color] = j;
        }
        ans[query[i].idx] = qry(query[i].l, query[i].r);
    }

    rep(i, 0, q) cout << ans[i] << '\n';
}