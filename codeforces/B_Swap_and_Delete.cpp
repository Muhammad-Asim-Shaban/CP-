#include<bits/stdc++.h>
using namespace std;
void solve()
{
        string str;
        cin>>str;
        int n=str.length();
        int z=count(str.begin(),str.end(),'0');
        int o=count(str.begin(),str.end(),'1');
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            o--;
            else
            z--;
            if(o<0 || z<0)
            {
                cout<<n-i<<endl;
                return;
            }
        }
        cout<<0<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    solve();

}