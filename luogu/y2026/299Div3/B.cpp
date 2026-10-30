#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

const int N = 1e5 + 10;

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    s = '1' + s;
    bitset<N> st;
    for (int i = 0; i < s.size(); i++) st[i] = s[i] - '0';
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        cnt++;
        if (i == 1) st = ~st;
        else 
            for (int j = i; j <= n; j += i) st.flip(j);
    }
    cout << cnt << '\n';
}