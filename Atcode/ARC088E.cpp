#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repe(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2e5 + 10, M = 30;

array<int, N> prePos, wfTree, posTree, finalPos, preFix;
array<int, M> endPos;

int n, m, odd = 0;
 
int lowbit(int i) {
    return i & -i;
}

void add(array<int, N> &T, int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) T[i] += k;
}

void add(int c, int x) {
    prePos[x] = endPos[c];
    endPos[c] = x;
}

int pop(int c) {
    int t = endPos[c];
    endPos[c] = prePos[endPos[c]];
    return t;
}

int sum(array<int, N> &T, int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += T[i];
    return ans;
}

void confirmFinalPos(string &s) {

    repe(i, 1, n) {
        int c = s[i] - 'a';
        add(c, i);
    }

    repe(i, 1, n) add(posTree, i, 1);

    repe(l, 1, n) {

        int c = s[l] - 'a';

        if (finalPos[l] == 0) {
            int r = pop(c);
            if (l < r) {
                int k = sum(posTree, l);
                finalPos[l] = k;
                finalPos[r] = n - k + 1;
            }
            else {
                odd++;
                finalPos[l] = (n + 1) >> 1;
            }
            add(posTree, r, -1);
        }
    }
}

int initPrefix() {
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += sum(wfTree, finalPos[i] - 1);
        add(wfTree, finalPos[i], 1);
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string src, t; src = ' '; cin >> t; 
    src += t; n = src.size() - 1;

    confirmFinalPos(src);

    int ans = initPrefix();

    if (odd <= 1) cout << ans << '\n';
    else cout << -1 << '\n'; 
    
}