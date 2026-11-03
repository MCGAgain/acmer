#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
#define int long long
typedef long long ll;
using namespace std;



void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int p, q, r, s, n, a, b;
    cin >> n >> a >> b >> p >> q >> r >> s;

    int M = a + b, D = a - b;

    for (int i = p; i <= q; i++) {

        for (int j = r; j <= s; j++) {

            if (i + j == M || i - j == D) cout << '#';
            else cout << '.';
        }

        cout << '\n';
    }

}