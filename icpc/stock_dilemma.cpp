#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vec;
vector<ll>dp(100005,-1);
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        ll n;
        cin>>n;
        vec.resize(n);
        for(ll i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        cout<<result()
    }
}