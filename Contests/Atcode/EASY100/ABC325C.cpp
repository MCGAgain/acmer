#include <iostream>
#include <queue>


using namespace std;


typedef pair<int, int> PII;
const int N = 1010;
int gra[N][N];
int h, w, dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1}; 
bitset<N> vis[N];

void ds() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) 
            cout << (int)gra[i][j] << ' ';
        cout << '\n';
    }

}

void bfs(int x, int y, int c) {
    queue<PII> q;
    q.push({x, y});

    while (q.size()) {
        PII t = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if (nx < 1 || ny < 1 || nx > h || ny > w) continue;
            if (gra[nx][ny] != c || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') gra[i][j + 1] = 1;
        }
    }
    
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!vis[i][j]) {
                bfs(i, j, gra[i][j]);
                if (gra[i][j] == 1) cnt++;
            }
        }
    }

    cout << cnt << '\n';

}