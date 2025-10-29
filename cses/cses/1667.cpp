#include<bits/stdc++.h>
using namespace std;
void bfs(int start,int V,vector<int> adj[])
{
    vector<bool> visited(V+1,false);
    queue<int> q;
    vector<int> dist(V+1,INT_MAX);
    dist[1]=0;
    vector<int> parent(V+1);
    visited[start]=true;
    q.push(start);
    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        //cout<<current<<" ";
        for(int neighbor: adj[current])
        {
            if(!visited[neighbor])
            {
                if(dist[neighbor]==INT_MAX)
                {
                    dist[neighbor]=dist[current]+1;
                    parent[neighbor]=current;
                }
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    if(dist[V]==INT_MAX)
    cout<<"IMPOSSIBLE"<<endl;
    else
    {
        cout<<dist[V]+1<<endl;
        vector<int> ans;
        ans.push_back(V);
        int temp=V;
        while(parent[temp]!=1)
        {
            ans.push_back(parent[temp]);
            temp=parent[temp];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1,n,adj);
}