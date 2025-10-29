// #include<bits/stdc++.h>
// using namespace std;
// char vec[1002][1002];
// int dp[1002][1002];
// int mod=1e9+7;
// int rec(int i,int j)
// {
//     if(vec[i][j]=='*')
//     return 0;
//     if(i<0||j<0)
//     return 0;
//     if(i==0&&j==0)
//     return 1;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     return  dp[i][j]=rec(i-1,j)+rec(i,j-1)%mod;
// }
// int main()
// {
//     int n;
//     cin>>n;
//    for (int i = 0; i < n; i++) {
//     string row;
//     cin >> row;
//     for (int j = 0; j < n; j++) {
//         vec[i][j] = row[j];
//     }
// }
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(n-1,n-1);
// }



#include<bits/stdc++.h>
using namespace std;
char vec[1002][1002];

int mod=1e9+7;
int main()
{
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++)
    {  
        for(int j=0;j<w;j++)
        {
            cin>>vec[i][j];
        }
    }
    int dp[n][w];
    memset(dp,0,sizeof(dp));
    dp[0][0]=(vec[0][0]=='.')?1:0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(vec[i][j]=='#')continue;
            if(i>0)
            dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
            if(j>0)
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][w -1]<<endl;

}
