#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
#define int long long

using namespace std;

const int N = 3e4 + 10;
array<int, N> indexTree1, indexTree2;
int n;

int lowbit(int i) {
    return i & -i;
} 

void add(array<int, N> &Tree, int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) Tree[i] += k;
}

int sum(array<int, N> &Tree, int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += Tree[i];
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n; vector<int> a(n + 1), help;
    repe(i, 1, n) cin >> a[i];

    help = a; sort(help.begin() + 1, help.end());
    help.erase(unique(help.begin() + 1, help.end()), help.end());

    repe(i, 1, n) a[i] = lower_bound(help.begin() + 1, help.end(), a[i]) - help.begin();

    int ans = 0;
    repe(i, 1, n) {
        ans += sum(indexTree2, a[i] - 1);

        add(indexTree1, a[i], 1);
        add(indexTree2, a[i], sum(indexTree1, a[i] - 1));   
    }

    cout << ans << '\n';

}