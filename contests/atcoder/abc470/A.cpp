#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) cout << "Fizz" << '\n';
        else cout << i << '\n';
    }

}