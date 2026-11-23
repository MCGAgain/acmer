#include <iostream>

using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x0, x1, y0, y1; cin >> x0 >> y0 >> x1 >> y1;

    int dx = x1 - x0, dy = y1 - y0;

    int nx = -dy, ny = dx;

    cout << x1 + nx << ' ' << y1 + ny << ' ' << x0 + nx << ' ' << y0 + ny << '\n';

}