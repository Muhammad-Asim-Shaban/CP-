#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st)
{
    visited[i]=true;
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            dfs(it,adj,visited,st);
        }
    }

    st.push(i);
}
void dfsreverse(int i,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&ans,int anse)
{
    visited[i]=true;
    ans[i]=anse;
    for(auto it:adj[i])
    {
        if(!visited[it])
        {
            dfsreverse(it,adj,visited,ans,anse);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1),rev(n+1); //adjancency list
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    stack<int> st;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,st);    //first call fill stack.
        }
    }
    
    //cout<<st.size()<<endl;
    fill(visited.begin(),visited.end(),false);
    int anse=0;
    vector<int> ans(n+1,0);
    while(!st.empty())
    {
        int el=st.top();
        st.pop();
        if(!visited[el])
        {
            anse++;
            dfsreverse(el,rev,visited,ans,anse);
        }
        //ans[el]=anse;
    }   
    cout<<anse<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}