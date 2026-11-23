#include <iostream>
#include <cstring>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int Tree[N<<2], n;

int lowbit(int i) {
    return i & -i;
}

void add(int k, int x) {
    for (int i = k; i <= 200; i += lowbit(i)) Tree[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += Tree[i];
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s; n = s.size();
    s = " " + s;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += sum(s[i] - 1);
        add(s[i], 1);
    }

    cout << cnt << '\n';
}

// char help[N];
// int cnt = 0;
// char s[N];

// void partition(int l, int mid, int r) {
//     int lp = l, ip = l, rp = mid + 1;

//     while (lp <= mid && rp <= r) {
//         if (s[lp] >= s[rp]) help[ip++] = s[lp++];
//         else {
//             cnt += mid - lp + 1;
//             help[ip++] = s[rp++];
//         }
//     }
//     while (lp <= mid) help[ip++] = s[lp++];
//     while (rp <= r) help[ip++] = s[rp++];

//     for (int i = l; i <= r; i++) s[i] = help[i];

// } 

// void cnt_rev(int l, int r) {
//     if (l >= r) return;
//     int mid = l + r >> 1;

//     cnt_rev(l, mid);
//     cnt_rev(mid + 1, r);
//     partition(l, mid, r);
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> s;

//     cnt_rev(0, strlen(s) - 1);

//     cout << cnt << '\n';


// } 