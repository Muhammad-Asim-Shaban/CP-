// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// int dp[100005];
// ll frog2(vector<ll> a,ll n,ll k)
// {
//     if(n==0) return 0;
//     ll ls=LONG_LONG_MAX;
//     for(int i=1;i<=k;i++)
//     {
//         ll ab=LONG_LONG_MAX;
//         if(dp[n]!=-1)
//         {
//             return dp[n];
//         }
//         if(n-i>=0)
//         {
//             ab=frog2(a,n-i,k)+abs(a[n]-a[n-i]);
//         }
//         ls=min(ab,ls);
//     }
//     return dp[n]= ls;
// }
// int main()
// {
//     ll n,k;
//     cin>>n>>k;
//     vector<ll> a(n);
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     memset(dp,-1,sizeof(dp));
//     frog2(a,n-1,k);
//     cout<<dp[n-1];
// }


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> h(n);
    for(int i=0;i<n;i++)
    cin>>h[i];
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        ll minsteps=LONG_LONG_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                ll jump=dp[i-j]+ abs(h[i]-h[i-j]);
                minsteps=min(minsteps,jump);
            }
            dp[i]=minsteps;
        }
    }
    cout<<dp[n-1];

}