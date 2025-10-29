#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<bool>&visited,vector<bool>&instack,vector<vector<int>>&adj)
{
    visited[i]=true;
    instack[i]=true;
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            if(dfs(it,visited,instack,adj)==true) return true;
        }
        else if(instack[it]==true)
        {
            return true;
        }
    }
    instack[i]=false;
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        adj[i+1].push_back(vec[i
    }
    for(int i=0;i<n-1;i++)
    {
        if(vec[vec[vec[i+1]]]==i+1)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}