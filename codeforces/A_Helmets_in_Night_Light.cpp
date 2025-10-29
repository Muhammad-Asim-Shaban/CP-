#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        long long n,p;
        cin>>n>>p;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<pair<ll,ll>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            v[i]={b[i],a[i]};
        }
        sort(v.begin(),v.end());
        ll minimumcost=p;
        ll alreadyshared=1;
        for(auto it:v)
        {
            ll canbeshared=it.second;
            ll sharingcost=it.first;
            if(sharingcost>=p)
            {
                break;
            }
            if(alreadyshared+canbeshared>n)
            {
                minimumcost+=(n-alreadyshared)*sharingcost;
                alreadyshared=n;
                break;
            }
            else
            {
                minimumcost+=canbeshared*sharingcost;
                alreadyshared+=canbeshared;
            }
        }
        minimumcost+=(n-alreadyshared)*p;
        cout<<minimumcost<<endl;
    }
}