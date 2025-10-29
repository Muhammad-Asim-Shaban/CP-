#include<bits/stdc++.h>
using namespace std;
int inf=1e9;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
    cin>>vec[i];
    vector<int> dp(k+1,inf);
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        for(int c:vec)
        {
            if(i-c>=0)
            dp[i]=min(dp[i],1+dp[i-c]);
        }
    }
    cout<<dp[k];
}