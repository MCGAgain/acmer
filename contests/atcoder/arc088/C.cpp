#include <iostream>
#include <array>
#include <algorithm>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2e5 + 10;
array<int, N> a, help, prePos;
array<int, N << 2> Tree;
array<int, 30> endPos;
int n, odd = 0;

int lowbit(int i) {
    return i & -i;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) Tree[i] += k;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += Tree[i];
    return res;
}

void push(int c, int x) {
    prePos[x] = endPos[c];
    endPos[c] = x;
}

int pop(int c) {
    int t = endPos[c];
    endPos[c] = prePos[endPos[c]];
    return t;
}

int pair_cnt = 0;
void merge(const int l, const int m, const int r) {
    int i = l, lp = l, rp = m + 1;
    while (lp <= m && rp <= r) {
        if (a[lp] <= a[rp]) help[i++] = a[lp++];
        else {
            pair_cnt += m - lp + 1;
            help[i++] = a[rp++];
        }
    }
    while (lp <= m) help[i++] = a[lp++];
    while (rp <= r) help[i++] = a[rp++];
    for (int j = l; j <= r; j++) a[j] = help[j];
}

void reverse_pair(int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    reverse_pair(l, m);
    reverse_pair(m + 1, r);
    merge(l, m, r);
}

void init_final_pos(string &s) {
    rrep(i, 1, n) {
        int c = s[i] - 'a';
        push(c, i);
    }

    rrep(i, 1, n) add(i, 1);

    rrep(l, 1, n) {
        int c = s[l] - 'a';

        if (a[l] == 0) {
            int r = pop(c);
            if (l < r) {
                int k = sum(l);
                a[l] = k;
                a[r] = n - k + 1;
            }
            else {
                odd++;
                a[r] = (1 + n) >> 1;
            }
            add(r, -1);
        }
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    s = " " + s;
    n = s.size() - 1;
    init_final_pos(s);
    reverse_pair(1, n);

    if (odd <= 1) cout << pair_cnt << '\n';
    else cout << -1 << '\n';
}