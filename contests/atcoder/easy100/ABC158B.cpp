#include <iostream>
#define endl '\n'
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b; cin >> n >> a >> b;

    int part_1 = n / (a + b);
    int r = n - part_1 * (a + b);

    int part_2 = r > a ? a : r;

    cout << part_1 * a + part_2 << endl;

}