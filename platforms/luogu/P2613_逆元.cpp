#include <iostream>
#define int long long
using namespace std;

const int MOD = 19260817;

int qmi(int a, int k, int p) {
    int ans = 1; a %= MOD;
    while (k) {
        if (k & 1) ans = ans * a % p;
        a = a * a % MOD;
        k >>= 1;
    }
    return ans;
}

int read() {
    char ch;
    int ans = 0;
    while ((ch = getchar()) < '0' || ch > '9') ;
    while ('0' <= ch && ch <= '9') {
        ans = (ans * 10 % MOD + (ch - '0')) % MOD;
        ch = getchar();
    }
    return ans;
}

signed main() {
    int a = read(), b = read();
    if (!b) cout << "Angry!" << '\n';
    else cout << a * qmi(b, MOD - 2, MOD) % MOD << '\n';
}