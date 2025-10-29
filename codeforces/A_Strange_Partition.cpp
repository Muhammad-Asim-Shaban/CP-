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
        vector<ll>vec(n);
        ll min=0;
        ll max=0;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        for(int i=0;i<n;i++)
        {
            max+=ceil(vec[i]*1.0/x);
            min+=vec[i];
        }
        min=ceil(min*1.0/x);
        cout<<min<<" "<<max<<endl;
    }
}