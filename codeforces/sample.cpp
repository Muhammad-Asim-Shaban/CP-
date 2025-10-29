#include<bits/stdc++.h>
using namespace std;
int inf=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    long long x=0;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        x+=vec[i];

    }
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int c:vec)
    {
        for(int i=1;i<=x;i++)
        {
            if(i-c>=0)
            {
                dp[i]=(dp[i]+dp[i-c])%inf;
            }
        }
    }
    cout<<dp[x]<<endl;
}