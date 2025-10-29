#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(),vec.end(),[](auto &a,auto &b){
        return a.second<b.second;
    });
    int count=0;
    int prev=0;
    for(auto &m:vec)
    {
        if(m.first>=prev)
        {
            count++;
            prev=m.second;
        }
    }
    cout<<count<<endl;
}