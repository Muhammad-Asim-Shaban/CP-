#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        vector<ll> prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+(str[i]=='W');
        }
        ll mincells=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            ll diff=prefix[i+k]-prefix[i];
            mincells=min(mincells,diff);
        }
        cout<<mincells<<endl;
    }
}