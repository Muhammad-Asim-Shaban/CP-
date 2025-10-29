// #include<bits/stdc++.h>
// using namespace std;
// long long dp[5001][5001];
// long long solve(vector<long long>&vec,int i,int j)
// {
//     if(i>j) return 0;
//     if(i==j) return vec[i];
//     if(dp[i][j]!=-1) return dp[i][j];
//     long long tl=vec[i]+min(solve(vec,i+2,j),solve(vec,i+1,j-1));
//     long long tr=vec[j]+min(solve(vec,i,j-2),solve(vec,i+1,j-1));
//     return dp[i][j]= max(tl,tr);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<long long> vec(n);
//     for(int i=0;i<n;i++)
//     cin>>vec[i];
//     memset(dp,-1,sizeof(dp));
//     cout<<solve(vec,0,n-1);
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5001][5001];
int main()
{
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    } 
    for(int i=0;i<n;i++)
    dp[i][i]=vec[i];
    for(int len=2; len<=n; len++) {
        for(int i=0; i+len-1<n; i++) {
            int j = i+len-1;
            long long takeLeft = vec[i] + min((i+2<=j ? dp[i+2][j] : 0),
                                              (i+1<=j-1 ? dp[i+1][j-1] : 0));
            long long takeRight = vec[j] + min((i<=j-2 ? dp[i][j-2] : 0),
                                               (i+1<=j-1 ? dp[i+1][j-1] : 0));
            dp[i][j] = max(takeLeft, takeRight);
        }
    }

    cout << dp[0][n-1];
}