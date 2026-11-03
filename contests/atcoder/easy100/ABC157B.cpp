#include <iostream>
#define int long long
using namespace std;
typedef pair<int, int> PII;
const int N = 20;

int g[N][N];
bool st[N][N];

PII find(int x) {
    for (int i = 1; i <= 3; i++) 
        for (int j = 1; j <= 3; j++) {
            if (g[i][j] == x) return {i, j};
        }
    return {-1, -1};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) 
            cin >> g[i][j];
    int x; while (cin >> x) {
        PII t = find(x);
        if (t.first != -1) st[t.first][t.second] = 1;
    }

    for (int i = 1; i <= 3; i++) {
        int sum = 0;
        for (int j = 1; j <= 3; j++) sum += st[i][j];
        if (sum == 3) {
            cout << "Yes" << '\n'; return 0;
        }
    }
    for (int i = 1; i <= 3; i++) {
        int sum = 0;
        for (int j = 1; j <= 3; j++) sum += st[j][i];
        if (sum == 3) {
            cout << "Yes" << '\n'; return 0;
        }
    }
    int sum = 0;
    for (int i = 1, j = 1; i <= 3 && j <= 3; i++, j++) 
        sum += st[i][j];
    if (sum == 3) {
        cout << "Yes" << '\n'; return 0;
    }
    sum = 0;
    for (int i = 1, j = 3; i <= 3 && j >= 1; i++, j--) 
        sum += st[i][j];
    if (sum == 3) {
        cout << "Yes" << '\n'; return 0;
    }

    cout << "No" << '\n';
}