#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll count=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                count++;
            }
        }
        ll ans=0;
        bool zero_found = false;
        ll left=0;
        ll right=n-1;
        while(left<n&&a[left]==0)
        {
            left++;
        }
        while(a[right]==0)
        {
            right--;
        }
        for(ll i=left;i<=right;i++)
        {
            if(a[i]==0)
            {
                zero_found=true;
            }
        }
        if(count==n)
        cout<<0<<endl;
        else if(zero_found)
        cout<<2<<endl;
        else
        cout<<1<<endl;
    }
}