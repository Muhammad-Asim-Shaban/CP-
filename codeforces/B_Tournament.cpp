#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,j,k;
        cin>>n>>j>>k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        --j;
        ll lower=0;
        ll upper=0;
        ll equal=0;
        for(ll i=0;i<n;i++)
        {
            if(a[j]>a[i])
            {
                lower++;
            }
            else if(a[j]<a[i])
            {
                upper++;
            }  
            else if(a[j]==a[i])
            {
                equal++;
            } 
        }
       // cout<<"lower: "<<lower<<" upper: "<<upper<<" equal:"<<equal<<endl;
        if(upper!=0)
        {
            ll value=upper-1;
            upper=upper-value;
        }
        if(equal!=0)
        {
            ll value=equal-1;
            equal=equal-value;
        }
        if(lower!=0)
        {
            lower=0;
        }
          //cout<<"lower: "<<lower<<" upper: "<<upper<<" equal:"<<equal<<endl;
        if((upper+lower+1)<=k)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}