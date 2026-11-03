#include<iostream>
#include<set>
#include<cstring>
using namespace std;
const int MAX = 4e6+5;
bool vis[MAX];
int ans[MAX];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        int n;cin>>n;
        if(n==1)
        {
            cout<<1<<' ';
            cout<<'\n';
            continue;
        }
        if(n==5)
        {
            cout<<"1 4 2 3 5\n";
            continue;
        }

        int temp = (int)sqrt((n-1)*2);
        vector<int> wq;
        for(int i = 2;i<=temp;i++)
        {
            int a = i*i;
            if(i%2==0)
            {
                int a1 = a/2-1,a2 = a/2+1;
                wq.push_back(a1);
                wq.push_back(a2);
                vis[a1] = 1;
                vis[a2] = 1;
            }
            else
            {
                int a1 = a/2-1,a2 = a/2+1;
                wq.push_back(a1);
                wq.push_back(a2);
                vis[a1] = 1;
                vis[a2] = 1;
            }
        }
        int tot = 1;
        for(int i = 1;i<=wq.size();i++)
        {
            ans[tot] = wq[i];
            vis[wq[i]] = 1;
            tot+=2;
        }
        tot = 2;
        int tet = 1;
        for(int i = 1;i<=wq.size();i++)
        {
            while(vis[tet]==1) tet++;
            ans[tot] = tet;
            tot+=2;
        }

        while(tet<=n)
        {
            while(vis[tet]==1) tet++;
            ans[tot++] = tet;
            vis[tet]=1;
        }
        
        for(int i = 1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}