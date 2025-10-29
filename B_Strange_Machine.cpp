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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        bool check=false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='B')
            {
                check=true;
            }
        }
        for(int i=0;i<q;i++)
        {   
            int in;
            cin>>in;
            if(check==false)
            {
                cout<<in<<endl;
                continue;   
            }
            int op=0;
            int it=0;
            while(in>0)
            {
                if(s[it]=='A')
                {
                    in--;
                    op++;
                }
                else
                {
                    in/=2;
                    op++;
                }
                it++;
                if(it==s.length())
                {
                    it=0;
                }
                if(in==0)
                {
                    break;
                }
            }
            cout<<op<<endl;
        }
    }
}