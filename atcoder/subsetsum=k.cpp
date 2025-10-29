#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,k;
    cin>>q>>k;
    while(q--)
    {
        map<int,int> mp;
        char op;
        int n;
        cin>>op>>n;
        if(op=='+')
        {
            mp[n]++;
            vector<int> vec;
            auto it=mp.begin();
            while(it!=mp.end())
            {
                int ip=it->second;
                for(int i=1;i<=ip;i++)
                vec.push_back((it->first));
                it++;
            }
            int s1=vec.size();
            int dp[s1+1][k+1];
             for(int i=0;i<s1+1;i++)
            {
                for(int j=0;j<k+1;j++)
                {
                    if(i==0||j==0)
                    dp[i][j]=0;
                }
            }
            for(int i=1;i<=s1;i++)
            {
                for(int j=1;j<=k;j++)
                {
                    if(vec[i-1]<=j)
                    {
                        dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            cout<<dp[n][W];
        }
    }
}