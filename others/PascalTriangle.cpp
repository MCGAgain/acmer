#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

void QueueOut(int n) {
    queue<int> q, tq;
    int pre = 0, cur = 0;   
    for (int i = 0; i <= n; i++) {

        pre = 0;
        while (q.size()) {
            cur = q.front(); q.pop();
            cout << cur << ' ';
            tq.push(pre + cur);
            pre = cur;
        }
        cout << '\n';
        swap(q, tq);
        q.push(1);
    }
}

void ArrOut(int n) {
    const int N = 1000;
    int a[N];
    memset(a, 0, sizeof a);
    a[1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {  //借用上一行的信息，滚动数组，逆序遍历
            cout << (a[j] = a[j] + a[j - 1]) << ' ';
        }
        cout << '\n';
    }
}

void SingalOut(int n) {
    int c;
    for (int i = 0; i < n; i++) {
        c = 1;
        for (int j = 0; j <= i; j++) {
            cout << c << ' ';
            c = c * (i - j) / (j + 1);  //组合数迭代表达
        }
        cout << '\n';
    }
}

void SingalLineOut(int n) {
    for (int i = 0; i < n; i++) for (int j = 0, c = 1; j <= i; c = c * (i - j) / (j + 1), j++) cout << c << " \n"[i == j];
}

signed main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        SingalLineOut(n);
    }
}