#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 110;
int a[N];

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
        if (i / 10 != (a[i] - 1) / 10) {
            cout << "No" << '\n';
            return 0;
        } 

    cout << "Yes" << '\n';


}