#include <iostream>
#include <bitset>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) if (x % i == 0) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    while (!is_prime(n)) n++;

    cout << n << '\n';

}