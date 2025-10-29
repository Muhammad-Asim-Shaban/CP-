#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ifstream cin("bcount.in");
    ofstream cout("bcount.out");
    ll n,q;
    cin>>n>>q;
    vector<ll> one(n+1,0);
    vector<ll> two(n+1,0);
    vector<ll> three(n+1,0);
    for(int i=0;i<n;i++)
    {
        one[i+1]=one[i];
        two[i+1]=two[i];
        three[i+1]=three[i];
        int pt;
        cin>>pt;
        if(pt==1)one[i+1]++;
        else if(pt==2) two[i+1]++;
        else if(pt==3) three[i+1]++;
    }
    for(int i=0;i<q;i++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<one[r]-one[l-1]<<" "<<two[r]-two[l-1]<<" "<<three[r]-three[l-1]<<endl;
    }
}