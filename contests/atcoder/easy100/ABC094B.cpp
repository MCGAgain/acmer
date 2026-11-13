#include <iostream>
#define int long long
#define endl '\n'
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

const int N = 110;

int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x; cin >> n >> m >> x;
    rrep(i, 1, m) cin >> a[i];


    int l = 1, r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }

    cout << min(m - l + 1, l - 1) << '\n';
    
}