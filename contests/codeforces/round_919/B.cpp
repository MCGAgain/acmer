/**
 * Problem: 919B
 * Tags: 
 * //
 * Rating: 1100
 * Link: https://codeforces.com/problemset/problem/919/B?utm_source=chatgpt.com
 */

#include <iostream>
#include <vector>
using namespace std;

#define S3

int k;

#ifdef S1
bool is_per(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum == 10;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;
    int cnt = 0, num = 0;
    while (cnt < k) {
        num++;
        if (is_per(num)) cnt++;
    }
    cout << num << '\n';
}
#endif

#ifdef S2
#define int long long
int cnt = 0, ans = -1;

void dfs(int len, int sum, int num ) {
    if (ans != -1) return;
    if (sum > len * 9) return;
    
    if (len == 0) {
        if (sum == 0) {
            cnt++;
            if (cnt == k) ans = num;
        }
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (sum - i >= 0) {
            dfs(len - 1, sum - i, num * 10 + i);
            if (ans != -1) return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;
    for (int i = 2;; i++) 
        for (int f = 1; f <= 9; f++) {
            dfs(i - 1, 10 - f, f);
            if (ans != -1) {
                cout << ans << '\n';
                return 0;
            }
        }
}

#endif 

#ifdef S3

const int N = 40, M = 15;
int f[N + 5][M + 5];

void init_dp() {
    f[0][0] = 1;

    for (int len = 1; len <= N; len++)
        for (int sum = 0; sum <= 10; sum++)
            for (int k = 0; k <= 9; k++)
                if (sum - k >= 0) f[len][sum] += f[len - 1][sum - k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> k;
    init_dp();
    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f[mid][10] >= k) r = mid;
        else l = mid + 1;
    }
    int rem_sum = 10;
    k -= f[l - 1][10];
    for (int base = l; base > 1; base--) {

        for (int p = (base == l) ? 1 : 0; p <= 9; p++) {
            if(rem_sum < p) continue;
            if (f[base - 1][rem_sum - p] >= k) {
                cout << p;
                rem_sum -= p;
                break;
            }
            k -= f[base - 1][rem_sum - p];
        }
    }
    cout << rem_sum << '\n';
}

#endif