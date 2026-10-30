#include <iostream>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 5e5 + 10;
int indexTree[N], n, m;

int lowbit(int i) {
    return i & -i;
}

int sum(int i) {
    int ans = 0;
    for (; i; i -= lowbit(i)) ans += indexTree[i];
    return ans;
}

void add(int i, int k) {
    for (; i <= n; i += lowbit(i)) indexTree[i] += k;
}

int range(int l, int r) {
    return sum(r) - sum(l - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    repe(i, 1, n) {
        int x; cin >> x;
        add(i, x); add(i + 1, -x);
    }  

    while (m--) {
        int op, x, y, k; cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            add(x, k); add(y + 1, -k);
        }
        else {
            cin >> x;
            cout << sum(x) << '\n';
        }
    }
}