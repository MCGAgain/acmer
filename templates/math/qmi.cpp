#include <iostream>
#define int long long
using namespace std;

int qmi(int a, int k, int p) {
    int res = 1;
    for (;k; k >>= 1, a = a * a % p) if (k & 1) res = res * a % p;
    return res; 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << qmi(3, 3, 100);
}