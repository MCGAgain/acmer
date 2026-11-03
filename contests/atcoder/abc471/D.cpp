#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Bat {
    ll s;
    ll w;

    bool operator < (const Bat& other) const {
        return (w - s) < (other.w - other.s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    ll v;
    cin >> q >> v;

    priority_queue<Bat> heap;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            ll t, w;
            cin >> t >> w;
            heap.push({t, w});
        } else {
            ll t;
            cin >> t;
            if (heap.empty()) {
                cout << -1 << '\n';
            } else {
                Bat top = heap.top();
                heap.pop();
                ll ans = min(v, top.w + (t - top.s));
                cout << ans << '\n';
            }
        }
    }

    return 0;
}