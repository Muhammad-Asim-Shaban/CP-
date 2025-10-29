#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<pair<ll,ll>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]={a[i]-x,a[i]+x};
        }
        ll ans=0;
        ll l=vec[0].first;
        ll r=vec[0].second;
        for(int i=1;i<n;i++)
        {
            l=max(l,vec[i].first);
            r=min(r,vec[i].second);
            if(l>r)
            {
                ans++;
                l=vec[i].first;
                r=vec[i].second;
            }
        }
        cout<<ans<<endl;

    }
}