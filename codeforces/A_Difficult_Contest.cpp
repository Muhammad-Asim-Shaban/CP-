#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        sort(str.begin(),str.end());
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
}