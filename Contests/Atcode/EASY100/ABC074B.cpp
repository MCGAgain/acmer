#include <iostream>
using namespace std;

const int N = 110;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, sum = 0; cin >> n >> k;
    
    while (n--) {
        int x; cin >> x;
        sum += min(x - 0, k - x);
    }    

    cout << sum * 2 << '\n';

}