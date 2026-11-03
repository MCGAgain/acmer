#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;


const ll MAX = 5e8;


void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll x; cin >> x;

    if (x <= MAX / x) {
        cout << "O(n^2)" << '\n';
        return 0;
    }
    else if (x <= MAX) {
        cout << "O(n)" << '\n';
        return 0;
    }
    else cout << "O(1)" << '\n';

}