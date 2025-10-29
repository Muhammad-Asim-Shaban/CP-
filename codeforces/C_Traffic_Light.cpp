#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char c;
        cin>>c;
        string str;
        cin>>str;
        str+=str;
        int index=-1;
        int ans=0;
        int size=str.length()-1;
        for(int i=size;i>=0;i--)
        {
            if(str[i]=='g')`
            {
                index=i;
            }
            else if(str[i]==c)
            {
                if(index==-1)
                {
                    continue;
                }
                else
                {
                    ans=max(ans,index-i);
                }
            }
            
        }
        cout<<ans<<endl;
    }
}