#include <iostream>
#include <bitset>
#include <vector>
#include <cstdlib>
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

const int N = 10;

bitset<N> used;
int r, n, cnt;


void GetRank(int f, vector<int>& sample) {
    if (r != 0) return;

    static vector<int> path;
    if (f > n) {
        cnt++;
        if (path == sample) r = cnt;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        path.push_back(i); used[i] = 1;
        GetRank(f + 1, sample);
        path.pop_back(); used[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> p(n), q(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> q[i];

    r = 0; cnt = 0; GetRank(1, p);
    int rank_p = r;
    r = 0; cnt = 0; GetRank(1, q);
    int rank_q = r;

    cout << abs(rank_p - rank_q) << endl;
}