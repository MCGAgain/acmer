#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 2e5 + 10;
int a[N], n;

void solve() {
    vector<int> cnt_1, cnt_n1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt_1.push_back(i);
        if (a[i] == -1) cnt_n1.push_back(i);
    }

    if (cnt_1.empty()) {
        if (cnt_n1.size() >= 1) {
            a[cnt_n1.front()] = 1;
            a[cnt_n1.back()] = 1;
            for (int i = 1; i <= n; i++) {
                if (a[i] == -1) cout << 0 << ' ';
                else cout << a[i] << ' ';
            }
            cout << '\n';
            return;
        }
        else {
            for (int i = 1; i <= n; i++) cout << 0 << ' ';
            cout << '\n';
            return;
        }
    }
    int maxLen = 1;
    int L = -1, R = -1;
    
    for (int i = 0; i + 1 < cnt_1.size(); i++) {
        int len = cnt_1[i + 1] - cnt_1[i] + 1;
        if (len > maxLen) {
            maxLen = len;
            L = cnt_1[i];
            R = cnt_1[i + 1];
        }
    }
    
    int l = cnt_1.front();
    for (int i : cnt_n1) {
        if (i < l) {
            int len = l - i + 1;
            if (len > maxLen) {
                maxLen = len;
                L = i;
                R = l;
            }
            break;
        }
    }
    
    int r = cnt_1.back();
    for (int i = cnt_n1.size() - 1; i >= 0; i--) {
        int idx = cnt_n1[i];
        if (idx > r) {
            int len = idx - r + 1;
            if (len > maxLen) {
                maxLen = len;
                L = r;
                R = idx;
            }
            break; 
        }
    }
    

    if (L != -1) a[L] = 1;
    if (R != -1) a[R] = 1;


    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) a[i] = 0;
        cout << a[i] << ' ';
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}