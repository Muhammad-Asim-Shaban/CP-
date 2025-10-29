#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        sum+=vec[i];
    }
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(int c:vec)
    {
        for(int s=sum;s>=0;s--)
        {
            if(dp[s])
            {
                dp[s+c]=true;
            }
        }
    }
    vector<int> results;
    for(int s=1;s<=sum;s++)
    {
        if(dp[s]) results.push_back(s);
    }
    cout<<results.size()<<endl;
    for(int i=0;i<results.size();i++)
    {
        cout<<results[i]<<" ";
    }
}