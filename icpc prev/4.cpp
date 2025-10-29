#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<int>>&vec,int n,int m,vector<vector<int>>&dp)
{
    if(n<0||m<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(n==0&&m==0)
    {
        return vec[n][m];
    }
    return dp[n][m]= vec[n][m]+ max(f(vec,n-1,m,dp),f(vec,n,m-1,dp));
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> vec(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>vec[i][j];
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        cout<<f(vec,n-1,m-1,dp);
    }
    
}