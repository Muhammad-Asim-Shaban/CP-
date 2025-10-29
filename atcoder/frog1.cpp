// #include<bits/stdc++.h>
// using namespace std;
// //int dp[100005];
// int frog(vector<int> h,int n,int dp[])
// {
//     if(n==0) return 0;
//     int rs=INT_MAX;
//     if(dp[n]!=-1)
//     return dp[n];
//     int ls=frog(h,n-1,dp)+abs(h[n]-h[n-1]);
//     if(n>1) rs=frog(h,n-2,dp) + abs(h[n]-h[n-2]);
//     return dp[n]=min(ls,rs);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     int dp[n+1];
//     memset(dp,-1,sizeof(dp));
//     frog(a,n-1,dp);
//     cout<<dp[n-1]<<endl;
// }



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int r=INT_MAX;
        int l=dp[i-1] + abs(a[i]-a[i-1]);
        if (i>1)  r=dp[i-2] + abs(a[i]-a[i-2]);
        dp[i]=min(l,r);
    }   
    cout<<dp[n-1]<<endl;
}