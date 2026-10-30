#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define int long long
#define repe(i, a, b) for (int i = (a); i <= (b); i++) 

using namespace std;

const int N = 2e5 + 10;
string s = " ";
int n, odd = 0;

array<int, N> wfTree, posTree, finalPos, pre;
array<int, 30> h;

int lowbit(int i) {
    return i & -i;
}

void add(array<int, N> &T, int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) T[i] += k;
}

void add(int c, int x) {
    pre[x] = h[c];
    h[c] = x;
}

int pop(int c) {
    int t = h[c];
    h[c] = pre[h[c]];
    return t;
}

int sum(array<int, N> &T, int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += T[i];
    return ans;
}

void initLink() {
    repe(i, 1, n) {
        int c = s[i] - 'a';
        add(c, i);
    }
}

void initfinalPos() {
    repe(i, 1, n) add(posTree, i, 1);

    repe(l, 1, n) {
        int c = s[l] - 'a';

        if (finalPos[l] == 0) {
            int r = pop(c);

            if (l < r) {
                int k = sum(posTree, l);
                finalPos[l] = k;
                finalPos[r] = n + 1 - k;
            }
            else {
                odd++;  //出现奇数次字符的个数
                finalPos[l] = (1 + n) >> 1;
            }

            add(posTree, r, -1);
        }
    }
}

int initpreFix() {
    int ans = 0;
    
    if (odd > 1) return -1; 

    for (int i = n; i >= 1; i--) {
        ans += sum(wfTree, finalPos[i]);
        add(wfTree, finalPos[i], 1);
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t; cin >> t;
    s += t;
    n = s.size() - 1;

    initLink();
    initfinalPos();
    
    cout << initpreFix() << '\n';

}
