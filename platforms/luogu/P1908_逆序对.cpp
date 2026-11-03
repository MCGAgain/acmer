#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 5e5 + 10;

array<int, N> indexTree;

int n, m;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) indexTree[i] += k;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += indexTree[i];
    return ans;
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; vector <int> a (n + 1), help;
    repe(i, 1, n) cin >> a[i];

    help = a;
    sort(help.begin() + 1, help.end());
    help.erase(unique(help.begin() + 1, help.end()), help.end());

    repe(i, 1, n) {
        a[i] = lower_bound(help.begin() + 1, help.end(), a[i]) - help.begin();
    }

    int ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += sum(a[i] - 1); add(a[i], 1);
    }

    cout << ans << '\n';
}