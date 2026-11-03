#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;



void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b; cin >> a >> b;

    if (a - b == 9 || a + b == 9 || a * b == 9 || a == 9 * b) cout << "Nine" <<'\n';
    else cout << "Nein" << '\n';


}