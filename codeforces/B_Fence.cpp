#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<ll> prefix(n+1);
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+vec[i-1];
    }
    ll min=0;
    ll max=min+m;
    ll ans=8897787;
    ll index=-1;
    while(!(max>=prefix.size()))
    {
        ll temp=prefix[max]-prefix[min];
        if(temp<ans)
        {
            ans=temp;
            index=min+1;
        }
        max++;
        min++;
    }
    cout<<index<<endl;
}