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
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        bool check=false;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==k)
            {
                check=true;
                break;
            }
        }
        if(check)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}