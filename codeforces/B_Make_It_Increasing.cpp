#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll ans=0;
        for(ll i=n-2;i>=0;i--)
        {
            while(a[i]>=a[i+1])
            {
                ans++;
                a[i]/=2;
                if(a[i]==0)
                break;
            }
            if(a[i]==0 && a[i+1]==0)
            {
                ans=-1;
                break;
            }
        }
        cout<<ans<<endl;
    }
}