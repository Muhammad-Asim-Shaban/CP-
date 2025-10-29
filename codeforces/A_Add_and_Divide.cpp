#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll operations=INT_MAX;
        for(int ad=0;ad<32;ad++)
        {
            ll ops=ad;
            ll newb=b+ad;
            if(newb==1)
            continue;
            ll copya=a;
            while(copya>0)
            {
                copya/=newb;
                ops++;
            }
            operations=min(operations,ops);
        }
        cout<<operations<<endl;
    }
}