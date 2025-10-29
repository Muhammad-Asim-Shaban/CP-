#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<int> pr(n);
    vector<int> pa(n);
    for(int i=0;i<n;i++) cin>>pr[i];
    for(int i=0;i<n;i++) cin>>pa[i];
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=sum;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(pr[i-1]<=j)
            {
                dp[i][j]=max(pa[i-1] + dp[i-1][j-pr[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}