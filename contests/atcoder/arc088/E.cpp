#include <iostream>
#include <array>
#include <algorithm>
#define int long long
#define rrep(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

const int N = 2e5 + 10;

array<int, N << 2> Tree;
array<int, N> final_pos, help, prePos;
array<int, 30> endPos;

int n, odd = 0, ans = 0;

void push(int c, int x) {   //类链式前向星写法
    prePos[x] = endPos[c];
    endPos[c] = x;
}

int pop(int c) {
    int t = endPos[c];
    endPos[c] = prePos[endPos[c]];
    return t;
}

//----树状数组三件套----
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

void merge(array<int, N> &a, int l, int m, int r) {
    int i = l, lp = l, rp = m + 1;  // i 取 l 是为了在最后一行复制的时候不用映射下标，可以保持和原数组一一对应更新
    while (lp <= m && rp <= r) {
        if (a[lp] <= a[rp]) help[i++] = a[lp++];
        else {  //a[lp] > a[rp], 又因为左右两段区间严格单调，所以对于一个 a[rp]，由不等式的传递性可以知道，[lp, m] 这个范围都是严格大于 a[rp】的，进而得到闭区间个数m - lp + 1
            ans += m - lp + 1;
            help[i++] = a[rp++];
        }
    }
    while (lp <= m) help[i++] = a[lp++];
    while (rp <= r) help[i++] = a[rp++];
    for (int j = l; j <= r; j++) a[j] = help[j];
} 

void cnt_pair(array<int, N> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) >> 1;
    cnt_pair(a, l, m);
    cnt_pair(a, m + 1, r);
    merge(a, l, m, r);
}

void init_final_pos(string &s) {
    rrep(i, 1, n) {
        int c = s[i] - 'a';
        push(c, i);
    }

    rrep(i, 1, n) add(i, 1);

    rrep(l, 1, n) {
        int c = s[l] - 'a';
        
        if (!final_pos[l]) {
            int r = pop(c);

            if (l < r) {
                int k = sum(l);
                final_pos[l] = k;
                final_pos[r] = n - k + 1;
            }
            else {
                odd++;
                final_pos[r] = (1 + n) >> 1;
            }
            add(r, -1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    s = ' ' + s;
    n = s.size() - 1;
    init_final_pos(s);
    cnt_pair(final_pos, 1, n);

    if (odd <= 1) cout << ans << '\n';
    else cout << -1 << '\n';
}