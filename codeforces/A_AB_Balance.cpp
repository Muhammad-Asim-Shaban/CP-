#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
int t;
cin>>t;
while(t--)
{
cin>>s;
s[0]=s[s.size()-1];
cout<<s<<endl;
}
}