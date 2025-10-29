#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll int
int main()
{
    ll a,b;
    cin>>a>>b;
    vector<ll> vec(a);
    for(int i=0;i<a;i++)
    {
        cin>>vec[i];
    }
    vector<ll> dp(b+1,0);
    dp[0]=1;
    for(int i=1;i<=b;i++)
    {
        for(int j=0;j<a;j++)
        {
            if(vec[j]<=i)
            {
                dp[i]=(dp[i] + dp[i-vec[j]])%1000000007;
            }
        }
    }
    cout<<dp[b]<<endl;
}