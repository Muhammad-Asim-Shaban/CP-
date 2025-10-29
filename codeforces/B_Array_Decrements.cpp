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
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        ll c=a[0]-b[0];
        //cout<<"c value is "<<c<<endl;
        bool check=true;
        for(int i=1;i<n;i++)
        {
            if((a[i]-b[i])==c)
            {
                continue;
            }
            else
            {
                check=false;
                break;
            }
        }
        if(check==false)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
}