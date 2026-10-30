#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;

const int N = 1e7 + 10;
int prime[N], cnt = 0;
bitset<N> st;
string s;

void init(int n) {

    int M = 1; while (n--) M *= 10;
    M += 5;

    for (int i = 2; i <= M; i++) {
        if (!st[i]) {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt && prime[j] <= M / i; j++) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int getLen(int x) {
    int ans = 0; while (x) x /= 10, ans++; return ans;
}

string getPartten(string &p) {
    int id[200], idx = 0;
    memset(id, 0, sizeof id);
    string ans;

    for (int i = 0; i < p.size(); i++) {
        char c = p[i];
        if (!id[c]) id[c] = ++idx;
        ans += ('0' + id[c]);
    }
    return ans;
}
string getPartten(int p) {
    string t = to_string(p); return getPartten(t);
}

bool check(int d, string &p) {
    return getPartten(d) == getPartten(p);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    init(s.size());

    for (int i = 0; i < cnt; i++) {

        if (getLen(prime[i]) < s.size()) continue;
        if (getLen(prime[i]) > s.size()) break;
        if (check(prime[i], s)) {
            cout << prime[i] << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

}