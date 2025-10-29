#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,b,s;
        cin>>n>>k>>b>>s;
        ll mis=(k*b);
        ll mxs=(k*b)+(k-1)*n;
        if (s<mis || s>mxs)
        {
            cout<<-1<<endl;
        }
        else
        {
            vector<ll>ans(n,0);
            ans[0]=mis;
            s-=mis;
            for(int i=0;i<n;i++)
            {
                ll add=min(k-1,s);
                ans[i]+=add;
                s-=add;
            }
            for(ll i=0;i<n;i++)
            {       
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}