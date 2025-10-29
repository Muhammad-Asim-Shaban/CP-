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
        ll cnt=0;
        bool check=false;
        while(n!=1)
        {
            if(n%6==0)
            {
                n/=6;
                cnt++;
            }
            else
            {
                if(n%3==0)
                {
                    n*=2;
                    cnt++;
                }
                else
                {
                    cnt=-1;
                    check=true;
                    break;
                }
            }
        }
        if(check)
        cout<<-1<<endl;
        else
        cout<<cnt<<endl;
    }
}