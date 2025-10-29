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
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        map<ll,ll>m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        ll flag=0;
        for (auto i:m)
        {
            if(i.second==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<-1<<endl;
        }
        else
        {
            vector<ll> st(n);
            for(int i=0;i<n;i++)
            {
                st[i]=i+1;
            }
            ll l=0,r=0;
            while(r<n)
            {
                if(a[l]==a[r])
                {
                    r++;
                }
                else
                {
                    rotate(st.begin()+l,st.begin()+l+1,st.begin()+r);
                    l=r;
                }
            }
            rotate(st.begin()+l,st.begin()+l+1,st.begin()+r);
            for(auto i: st)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}