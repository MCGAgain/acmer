#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int num[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s; //C++20 之后不接受这种重载cin >> s + 1;
    s = " " + s;
    int n = s.size() - 1;

    // for (int i = 0, total = 0; i <= n; i++) {
    //     if (s[i] == '<') num[i] = ++total;
    //     else num[i] = total = 0;
    // }

    // for (int i = n - 1, total = 0; i >= 0; i--) {
    //     if (s[i + 1] == '>') num[i] = max(++total, num[i]);
    //     else total = 0;
    // }

    // int sum = 0;
    // for (int i = 0; i <= n; i++) sum += num[i];

    // cout << sum << '\n';

    for (int i = 1; i <= n; i++) 
        if (s[i] == '<') num[i] = num[i - 1] + 1;
    
    for (int i = n - 1; i >= 0; i--)
        if (s[i + 1] == '>') num[i] = max(num[i], num[i + 1] + 1);

    int sum = 0;
    for (int i = 0; i <= n; i++) sum += num[i];

    cout << sum << '\n';
}