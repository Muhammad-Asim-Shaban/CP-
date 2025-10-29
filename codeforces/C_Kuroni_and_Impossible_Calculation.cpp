#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p;
ll mul(ll a,ll b)
{
    return (1LL*a*b)%p;
}
int main()
{
    ll n;
    cin>>n>>p;
    if(n>p)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll res=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res=mul(res,abs(a[i]-a[j])%p);
        }
    }
    cout<<res<<endl;
}