#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    ll m;
    cin>>m;
    vector<ll> prefix(n+1);
    prefix[0]=0;
    for(int j=1;j<=n;j++)
    {
        prefix[j]=prefix[j-1]+vec[j-1];
    }
    sort(vec.begin(),vec.end());
    vector<ll> pre(n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+vec[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        ll t,l,r;
        cin>>t>>l>>r;
        if(t==1)
        {
            cout<<prefix[r]-prefix[l-1]<<endl;
        }
        else
        {
            cout<<pre[r]-pre[l-1]<<endl;
        }
    }
}