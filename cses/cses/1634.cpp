#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll int
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>dp(x+1,1e9);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-a[j]>=0)
            {
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    cout<<(dp[x]==1e9?-1:dp[x])<<endl;
}



    // cout<<"after anything"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=x;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }