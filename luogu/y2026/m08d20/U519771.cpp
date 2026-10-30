/**
 * Problem: U519771 线性筛求约数个数
 * Tags:
 *  //数论
 *  //线性筛
 *  //约数个数
 *  //积性函数
 * Rating: 暂无评定
 * Link: https://www.luogu.com.cn/problem/U519771
 */

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 1e7 + 10;

// int divs[N];

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int n; cin >> n;
//     for (int i = 1; i <= n; i++) 
//         for (int j = i; j <= n; j += i)
//             divs[j]++;
//     for (int i = 2; i <= n; i++) cout << divs[i] << ' ';
// }
// #include <iostream>
// #include <unordered_map>
// using namespace std;

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int n; cin >> n;
//     for (int a = 2; a <= n; a++) {
//         int x = a, cnt = 1, res = 1;
//         for (int i = 2; i <= x / i; i++, cnt = 1) {
//             while (x % i == 0) {
//                 cnt++;
//                 x /= i;
//             }
//             res *= cnt;
//         }
//         if (x > 1) res *= 2;
//         cout << res << ' ';
//     }
// }

// #include <iostream>
// #include <vector>
// #include <bitset>
// using namespace std;

// const int N = 1e7;
// bitset<N> st;
// int prime[N / 10], cnt = 0, n, num[N];

// void Lsieve() {
//     for (int i = 2; i <= n / i; i++) {
//         if (!st[i]) {
//             prime[cnt++] = i;
//             num[i] = 1;
//         }
//         for (int j = 0; j < cnt && i <= n / prime[j]; j++) {
//             st[prime[j] * i] = 1;
//             num[prime[j] * i] = num[i] + num[prime[j]];
//             if (i % prime[j] == 0) break;
//         }
//     }
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     cin >> n; num[1] = 1;
//     Lsieve();
//     for (int i = 1; i <= n; i++) cout << num[i] + 1 << ' ';
// }

#include <iostream>
#include <bitset>
using namespace std;

const int N = 1e7 + 10;
bitset<N> st;
int n, prime[N], cnt = 0, num[N], d[N];

void Lsieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            num[i] = 1, d[i] = 2;
            prime[cnt++] = i;
        }
        for (int j = 0, t; j < cnt && i <= n / prime[j]; j++) {
            t = i * prime[j];
            st[t] = 1;
            if (i % prime[j] == 0) {
                num[t] = num[i] + 1;
                d[t] = d[i] / (num[i] + 1) * (num[i] + 2);
                break;
            }
            num[t] = 1, d[t] = 2 * d[i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    Lsieve();
    for (int i = 2; i <= n; i++) cout << d[i] << ' ';
}