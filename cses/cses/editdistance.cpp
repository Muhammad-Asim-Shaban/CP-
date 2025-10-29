// #include<bits/stdc++.h>
// using namespace std;
// int dp[5001][5001];
// int rec(string s1,string s2,int n,int m)
// {
//     if(n<0)
//     {
//         return m+1;
//     }
//     if(m<0)
//     {
//         return n+1;
//     }
//     if(dp[n][m]!=-1)
//     return dp[n][m];
//     if(s1[n]==s2[m])
//     {
//         return dp[n][m]= rec(s1,s2,n-1,m-1);
//     }   
//     else
//     {
//         int one=1+rec(s1,s2,n-1,m);
//         int two=1+rec(s1,s2,n,m-1);
//         int three=1+rec(s1,s2,n-1,m-1);
//         int pt=min(one,two);
//         return dp[n][m]= min(pt,three);
//     }
// }
// int main()
// {
//     string s1,s2;
//     cin>>s1>>s2;
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(s1,s2,s1.length()-1,s2.length()-1);
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=INT_MAX;
        }
    }
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=m;i++) dp[0][i]=i;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
}