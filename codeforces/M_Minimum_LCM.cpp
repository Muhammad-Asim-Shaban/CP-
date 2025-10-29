#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ansa=1;
        ll ansb=n-1;
        for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ansa=n/i;
                ansb=n-ansa;
                break;
            }
        }
        cout<<ansa<<" "<<ansb<<endl;
    }
}