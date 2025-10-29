#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int one=0;
        int zero=0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='1') one++;
            else zero++;
        }
        int m=min(one,zero);
        if(m%2!=0)
        {
            cout<<"DA"<<endl;
        }
        else
        cout<<"NET"<<endl;
    }
}