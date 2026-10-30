#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <bitset>
#define int long long
typedef long long ll;
using namespace std;
typedef pair<int, int> PII;

vector<PII> wall;

bool cmp(PII & a, PII & b) {
    return a.second < b.second;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, d; cin >> n >> d;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        wall.push_back({l, r});
    }

    sort(wall.begin(), wall.end(), cmp);

    int s = wall[0].second, cnt = 1;

    for (int i = 1; i < wall.size(); i++) {
        if (wall[i].first > s + d - 1) {
            cnt++;
            s = wall[i].second;
        }
    }

    cout << cnt << '\n';

}