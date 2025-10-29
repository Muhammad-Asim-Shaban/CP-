#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll power(ll a,ll b)
{
    ll ans=1%mod;
    while(b>0)
    {
        if(b&1)
        {
            ans=1LL*ans*a%mod;
        }
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;
    }
}