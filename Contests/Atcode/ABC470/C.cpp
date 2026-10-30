#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
int num[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, ans = 0; cin >> n >> q;
    vector <int> idxs, nextIdxs;

    while (q--) {
        int op, x; cin >> op;
        if (op == 1) {
            cin >> x;
            if (!num[x]) idxs.push_back(x);
            ans = ans ^ num[x] ^ (++num[x]);
        }
        else {
            nextIdxs.clear();
            for (auto i : idxs) {

                ans = ans ^ num[i] ^ (num[i] - 1);
                num[i]--;
                if (num[i] > 0) nextIdxs.push_back(i); 

            }
            idxs.swap(nextIdxs);
        }
        cout << ans << '\n';
    }
}