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
        string s1,s2;
        cin>>s1>>s2;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool check=false;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
            {
                continue;
            }
            else
            {
                check=true;
                break;
            }
        }
        if(check) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}