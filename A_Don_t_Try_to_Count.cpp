#include<bits/stdc++.h>
using namespace std;
bool check(string s,string x)
{
    if(x.size()<s.size())
    {
        return false;
    }
    for(int i=0;i<x.size()-s.size()+1;i++)
    {
        if(x.substr(i,s.size())==s)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        string x0=s;
        string x1=x0+x0;
        string x2=x1+x1;
        string x3=x2+x2;
        string x4=x3+x3;
        string x5=x4+x4;
        long long ans=-1;
        if(check(t,x0))
        ans=0;
        else if(check(t,x1))
        ans=1;
        else if(check(t,x2))
        ans=2;
        else if(check(t,x3))
        ans=3;
        else if(check(t,x4))
        ans=4;
        else if(check(t,x5))
        ans=5;
        cout<<ans<<endl;
    }
}