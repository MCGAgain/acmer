#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e6 + 10;
int n, m;
array<int, N> colorPos/*查表，维护此种颜色最右侧的下标*/, a, ans /*离线答案*/, Tree /*树状数组*/;

struct elem {
    int l, r, index;

    bool operator< (const elem &o) const {
        return this->r < o.r;
    }
};

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
    cin.tie(0); cout.tie(0);

    cin >> n; repe(i, 1, n) cin >> a[i];
    cin >> m;
    vector<elem> query(m + 1);
    repe(i, 1, m) {
        cin >> query[i].l >> query[i].r;
        query[i].index = i;
    }

    sort(query.begin() + 1, query.end());   //按查询的又边界排序

    for (int i = 1, s = 1; i <= m; i++) {
        int l = query[i].l, r = query[i].r, idx = query[i].index;

        for (; s <= r; s++) {
            int color = a[s];
            
            if (colorPos[color]) {
                add(colorPos[color], -1);   //首次更新，映射里还没有位置
            }
            add(s, 1);
            colorPos[color] = s;
           
        }
        
        ans[idx] = range(l, r);
    }

    repe(i, 1, m) cout << ans[i] << '\n';
}