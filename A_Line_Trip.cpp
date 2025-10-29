#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        vector<int> ans;
        ans.push_back(abs(vec[0]-0));
        for(int i=1;i<n;i++)
        {
            int p=abs(vec[i]-vec[i-1]);
            ans.push_back(p);
        }
        int p=abs(x-vec[n-1]);
        ans.push_back(p+p);
        sort(ans.begin(),ans.end());
        cout<<ans[ans.size()-1]<<endl;
    }
}