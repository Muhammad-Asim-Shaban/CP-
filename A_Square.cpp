#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==b&&a==c&&a==d)
        {
            cout<<"YES"<<endl;
        }
        else if(b==a&&b==c&&b==d)
        {
            cout<<"YES"<<endl;
        }
        else if(c==a&&c==b&&c==d)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}