#include <iostream>
#include <bitset>
#include <algorithm>
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
const int N = 2e9;



signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    auto *st = new bitset<N + 10>;
    int *prime = new int[(int)1e8], cnt = 0, t;
    unsigned short *spf = new unsigned short[N + 10];

    for (int i = 2; i <= N; i++) {
        if (!(*st)[i]) {
            prime[cnt++] = i;
            spf[i] = 0;
        }
        for (int j = 0; prime[j] <= N / i; j++) {
            t = prime[j] * i;
            (*st)[t] = 1;
            spf[t] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    int cnter, x, ans = -1;
    rrep(num, 2, N) {
        cnter = 0;
        x = num;
        while (x > 1) {
            int p = spf[x] ? spf[x] : x;
            cnter++;
            x /= p;
        }
        ans = cnter > ans ? cnter : ans;
        cout << ans << '\n';
    }

    cout << ans << '\n';

    delete st;
    delete[] prime;
    delete[] spf;
}