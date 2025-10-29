#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int ans=0;
        //bool check=false;
        int two=0;
        bool check=false;
        for(int i=0;i<n;i++)
        {
           if(str[i]=='#')
           {
                if(two>=3)
                {
                    ans=2;
                    check=true;
                    break;
                }
                ans+=two;
                two=0;
           }
           else
           {
                two++;
           }
        }
        if(check)
        cout<<ans<<endl;
        else
        {
            if(two>=3)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<ans+two<<endl;
            }
        }
    }
}