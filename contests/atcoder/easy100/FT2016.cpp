#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b, passB = 0, pass = 0;

    string s; cin >> a >> b >> s;
    s = ' ' + s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'b') {
            passB++;
            if (pass < a + b && passB <= b) {
                cout << "Yes" << '\n';
                pass++;
            }
            else cout << "No" << '\n';
            
        }
        else if (s[i] == 'a') {
            
            if (pass < a + b) {
                cout << "Yes" << '\n';
                pass++;
            }

            else cout << "No" << '\n';
            
        }
        else cout << "No" << '\n';
    }

}