// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <cmath>
// #include <cstring>
// #include <bitset>
// typedef long long ll;
// using namespace std;



// void outlen(int n) {
//     for (int i = 1; i < n; i++) cout << "AR";
// }

// void outwidth(int n) {
//     for (int i = 1; i < n; i++) cout << "RC";
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int x; cin >> x;

//     if (x == 0) {
//         cout << "ATCODE" << '\n';
//         return 0;
//     }

//     for (int i = 1; i <= x / i; i++) {
//         if (x % i == 0) {
//             if (i * 2 + (x / i) * 2 - 1 <= 100) {
//                 outlen(i); cout << "ARC"; outwidth(x / i);
//                 cout << "\n";
//                 return 0;
//             }
//         }
//     }

// }

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<char> a;


int main() {
    int x; 
    cin >> x;

    if (x == 0) {
        cout << "ATCODER\n";
        return 0;
    }

    if (x <= 24) {
        cout << "A";
        for (int i = 0; i < x; i++) cout << "RC";
        cout << "\n";
        return 0;
    }

    int B = 24; int A = x / B; int r = x % B;

    for (int i = 0; i < A; i++) a.push_back('A');
    for (int i = 0; i < B - r; i++) a.push_back('C');
    if (r > 0) a.push_back('A');
    for (int i = 0; i < r; i++) a.push_back('C');

    for (int i = 0; i < a.size(); i++) {
        if (i > 0) cout << 'R';
        cout << a[i];
    }
    cout << '\n';

    return 0;
}