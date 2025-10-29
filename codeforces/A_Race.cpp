#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,x,y;
        cin>>a;
        cin>>x;
        cin>>y;
        ll ax,ay;
        ax=abs(a-x);
        bool check=false;
        ay=abs(a-y);
        for(ll i=1;i<=1000;i++)
        {
            ll bx,by;
            if(i==a)
            {
                continue;
            }
            bx=abs(i-x);    
            by=abs(i-y);
            if(bx<ax && by<ay)
            {
                check=true;
                cout<<"YES"<<endl;
                break;
            }   
        }
        if(!check)
        cout<<"NO"<<endl;
    }
}