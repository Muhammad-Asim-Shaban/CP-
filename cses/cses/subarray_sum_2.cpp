#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    map<ll,int>mp;
    mp[0]=1;    //edge case
    ll ans=0;
    ll prefixsum=0;
    for(ll x:arr)
    {
        prefixsum+=x;
        ans+=mp[prefixsum-m];
        mp[prefixsum]++;
    }
    cout<<ans<<endl;
    return 0;
}