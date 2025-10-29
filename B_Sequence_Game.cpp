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
        int m;
        cin>>m;
        vector<int> vec(m);
        for(int i=0;i<m;i++)
        {
            cin>>vec[i];
        }
        vector<int> ans;
        ans.push_back(vec[0]);
        for(int i=1;i<m;i++)
        {
            if(vec[i-1]<=vec[i])
            {
                ans.push_back(vec[i]);
            }
            else
            {
                ans.push_back(1);
                ans.push_back(vec[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}