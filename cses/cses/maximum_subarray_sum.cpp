#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll csum=a[0];
    ll maxsum=a[0];
    for(ll i=1;i<n;i++)
    {
        csum=max(a[i],csum+a[i]);
        maxsum=max(maxsum,csum);
    }
    cout<<maxsum<<endl;
    return 0;
}
