#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e6 + 10;

struct item {
    int l, r, idx;

    bool operator< (const item& o) const {
        return this->r < o.r;
    }
};

int n, m;
array<int, N> a, lastPos, Tree, ans;
array<item, N> query;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) Tree[i] += k;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += Tree[i];
    return ans;
}

int range(int l, int r) {
    return sum(r) - sum(l - 1);
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; repe(i, 1, n) cin >> a[i]; 
    cin >> m;
    repe(i, 1, m) {
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }

    sort(query.begin() + 1, query.begin() + 1 + m);

    int i = 1;
    repe(r, 1, m) {
        
        for (; i <= query[r].r; i++) {
            int color = a[i];

            if (lastPos[color]) {
                add(lastPos[color], -1);
            }

            add(i, 1);
            lastPos[color] = i;
        }

        ans[query[r].idx] = range(query[r].l, query[r].r);
    }

    repe(i, 1, m) cout << ans[i] << '\n';
}