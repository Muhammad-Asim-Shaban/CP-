#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool check=false;
        int count=0;
        int abc=0;
        for(int i=0;i<n;i++)
        {
            abc++;
            //cout<<"count value is "<<abc<<endl;
            if(check==false&&s[i]=='1')
            {
                //abc++;
                check=true;
                count++;
                //continue;
                abc=0;
                //cout<<"count runs"<<endl;
                continue;
            }
            if(s[i]=='1'&&abc>=k)
            {
                count++;
                abc=0;
                //cout<<"count runs second"<<endl;
            }
            if(s[i]=='1')
            {
                abc=0;
            }
            // if(s[i]=='0')
            // abc++;
        }
        cout<<count<<endl;
    }
}