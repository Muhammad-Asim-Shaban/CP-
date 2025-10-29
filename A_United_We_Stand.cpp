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
        vector<int> vec(n);
        bool check=false;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        int el;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                else if(vec[j]%vec[i]!=0)
                {
                    count++;
                }
            }
            if(count==n-1)
            {
                el=vec[i];
                check=true;
                break;
            }
        }
        if(check)
        {
            cout<<n-1<<endl;
            for(int i=0;i<n;i++)
            {
                if(vec[i]!=el)
                cout<<vec[i]<<" ";
            }
            cout<<endl;
            cout<<1<<endl;
            cout<<el<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}