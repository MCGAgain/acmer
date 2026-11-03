#include <iostream>
#include <algorithm>
#include <set>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repe(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
int a, b, c, cnt = 0;

bool isOdd() {
    return ((a & 1) || (b & 1) || (c & 1));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<int> begin, change; 
     cin >> a >> b >> c;
    begin.insert(a);begin.insert(b);begin.insert(c);

    while (!isOdd()) {
        change.clear();
        int ta = a, tb = b, tc = c;
        a = tb / 2 + tc / 2;
        b = ta / 2 + tc / 2;
        c = ta / 2 + tb / 2;

        change.insert(a);change.insert(b),change.insert(c);        

        if (begin == change) {
            cout << -1 << '\n';
            return 0;
        }
        cnt++;
    }

    cout << cnt << '\n';

}