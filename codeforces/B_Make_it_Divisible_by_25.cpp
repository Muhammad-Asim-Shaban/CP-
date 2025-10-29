#include<bits/stdc++.h>
using namespace std;
int operations(string str,string value)
{
    int size=value.size()-1;
    int ret=0;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]==value[size])
        {
            size--;
            if(size<0)
            {
                break;
            }
        }
        else
        {
            ret++;
        }
    }
    if(size>=0)
    {
        ret=INT_MAX;
    }
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        vector<string> pvalues={"00","25","50","75"};
        int ans=INT_MAX;
        for(auto value:pvalues)
        {
            ans=min(ans,operations(str,value));
        }
        cout<<ans<<endl;
    }
}