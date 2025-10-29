#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll xortill(ll n)
{
    ll a=n%4;
    if(a==0)return n;
    else if(a==1) return 1;
    else if(a==2) return n+1;
    else return 0;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll arrxor=xortill(a-1);
        if(arrxor==b)
        cout<<a<<endl;
        else if((arrxor^b)!=a)
        cout<<a+1<<endl;
        else
        cout<<a+2<<endl;

    }
}