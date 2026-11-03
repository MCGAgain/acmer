#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int h, w, k;

typedef struct {
    int x, y;
} idx;

void bfs(vector<vector<int>> &gra) {
    queue<idx> q;
    vector<vector<bool>> used(h + 10, vector<bool>(w + 10, 0));

    for (int i = 1; i <= h; i++) 
        for (int j = 1; j <= w; j++) 
            if (gra[i][j] == 2) q.push({i, j});

    int floor = 0;

    while (q.size() && ++floor <= k) {
        queue<idx> tq = q; while (q.size()) q.pop();
        
        while (tq.size()) {
            idx t = tq.front(); tq.pop();

            for (int i = 0; i < 4; i++) {
                int cx = t.x + dx[i], cy = t.y + dy[i];
                if (cx < 1 || cx > h || cy < 1 || cy > w) continue;
                if (used[cx][cy]) continue;
                if (gra[cx][cy] != 2 && gra[cx][cy] != -1) {
                    gra[cx][cy] = used[cx][cy] = 1;
                    q.push({cx, cy});
                }
            }
        }

    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> h >> w >> k;

    vector<vector<int>> gra(h + 10, vector<int>(w + 10, 0));
    vector<bool> col(w + 10, 0), row(h + 10, 0); 

    for (int i = 1; i <= h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') {
                col[j + 1] = 1; // 此列有标记
                row[i] = 1; // 此行有标记
                gra[i][j + 1] = -1;
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= h; i++) 
        for (int j = 1; j <= w; j++)
            if (!col[j] && !row[i]) gra[i][j] = 2;

    bfs(gra);

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) 
            if (gra[i][j] >= 1) cnt++;

    
    cout << cnt << '\n';
}