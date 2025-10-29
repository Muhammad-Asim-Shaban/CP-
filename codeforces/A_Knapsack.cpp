// #include<bits/stdc++.h>
// using namespace std;
// long long dp[102][100002];
// long long knapsack(vector<long long> w,vector<long long> v,long long W,long long N)
// {
//     if(N==0|| W==0)
//     return 0;
//     if(dp[N][W]!=-1)
//     return dp[N][W];
//     if(w[N-1]<=W)
//     {
//         return dp[N][W]= max(v[N-1]+knapsack(w,v,W-w[N-1],N-1),knapsack(w,v,W,N-1));
//     }
//     else
//     {
//         return dp[N][W]= knapsack(w,v,W,N-1);
//     }
// }
// int main()
// {
//     long long N,W;
//     cin>>N>>W;
//     memset(dp,-1,sizeof(dp));
//     vector<long long> w(N);
//     vector<long long> v(N);
//     for(long long i=0;i<N;i++)
//     {
//         cin>>w[i]>>v[i];
//     }
//     knapsack(w,v,W,N);
//     cout<<dp[N][W]<<endl;
// }




#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,W;
    cin>>n>>W;
    vector<ll> w(n);
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
    }
    ll dp[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(w[i-1]<=j)
            {
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W];
    }
    

}