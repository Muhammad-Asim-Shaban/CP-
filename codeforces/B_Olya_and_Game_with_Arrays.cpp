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
        vector<ll> secondelements;
        ll lowestfirstminimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ll m;
            cin>>m;
            vector<ll>a(m);
            for(auto &x: a)
            {
                cin>>x;
            }
            sort(a.begin(),a.end());
            secondelements.push_back(a[1]);
            lowestfirstminimum=min(lowestfirstminimum,a[0]);
        }
        sort(secondelements.begin(),secondelements.end());
        ll sumofelements=accumulate(secondelements.begin(),secondelements.end(),0LL);
        ll lowestsecondminimum=secondelements[0];
        ll answer=lowestfirstminimum+sumofelements-lowestsecondminimum;
        cout<<answer<<endl;
    }

}