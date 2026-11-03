#include <iostream>
#include <array>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 1e5 + 10;
int n, m;

array<int, N> indexTree, assistTree;

int lowbit(int i) {
    return i & -i;
}

void add(array<int, N> &T, int i, int k) {
    for (; i <= n; i += lowbit(i)) T[i] += k;
}

int sum(array<int, N> &T, int i) {
    int ans = 0;
    for (; i; i -= lowbit(i)) ans += T[i];
    return ans;
}

void add(int l, int r, int k) {
    add(indexTree, l, k); add(indexTree, r + 1, -k);
    add(assistTree, l, (l - 1) * k); add(assistTree, r + 1, - (r * k));
}

int range(int l, int r) {
    return sum(indexTree, r) * r - sum(assistTree, r) - sum(indexTree, l - 1) * (l - 1) + sum(assistTree, l - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    repe(i, 1, n) {
        int x; cin >> x;
        add(i, i, x);
    }

    while (m--) {
        int op, x, y, k; cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            add(x, y, k);
        }
        else {
            cin >> x >> y;
            cout << range(x, y) << '\n';
        }
    }
}