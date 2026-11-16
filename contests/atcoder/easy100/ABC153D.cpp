#include <iostream>
#include <cmath>
#define int long long
#define endl '\n'

using namespace std;

int qpow(int a, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = res * a;
        k >>= 1;
        a = a * a;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x; cin >> x;

    int k = 63 - __builtin_clzll(x) + 1; //这个是不会补全的，懒加载，__开头的编译器内建函数太多了

    cout << qpow(2, k) - 1 << endl;

}