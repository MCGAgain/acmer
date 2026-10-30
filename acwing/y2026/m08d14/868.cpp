/**
 * Problem: AcWing 868. 筛质数
 * Tags:
 *  //数论
 *  //埃氏筛
 *  //线性筛
 *  //质数
 * Rating: 简单
 * Link: https://www.acwing.com/problem/content/870/
 */

#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10; 

bool st[N];
int n;
vector<int> prime;

void naive_Esieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime.push_back(i);
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

void Esieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }    
}

void Lsieve() {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) prime.push_back(i);
        for (int j = 0; j <= prime.size() && prime[j] <= n / i; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    Esieve();
    cout << prime.size() << '\n';
}