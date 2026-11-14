#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e6 + 10;

bitset<N> st;

int f(int n) {
    if (n & 1) return 3 * n + 1;
    else return n / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s; cin >> s;
    int cnt = 1;
    while (!st[s]) {
        st[s] = 1;
        s = f(s);
        cnt++;
    }
    cout << cnt << '\n';
}