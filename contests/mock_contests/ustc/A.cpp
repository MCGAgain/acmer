#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>
typedef long long ll;
using namespace std;
int n;
const int MAX = 1e5+5;
int arr[MAX];
void solve() {
    cin>>n;
    for(int i =  1;i<=n;i++)
    {
        cin>>arr[i];
    }
    int ans = -1;
    for(int i = 1;i<=n;i++)
    {
        if(i>n/2+1)
        {
            cout<<ans<<' ';
            continue;
        }
        int temp = max(arr[i],arr[n-i+1]);
        ans = max(ans,temp);
        cout<<ans<<' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}