#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int sum=1;sum<=x;sum++)
        {
            int skipping=dp[i+1][sum];
            int picking=0;
            if(a[i]<=sum)
            {
                picking=dp[i][sum-a[i]];
            }
            dp[i][sum]=(skipping+picking)%1000000007;
        }
    }
    cout<<dp[0][x]<<endl;
}
int main()
{
    solve();
}