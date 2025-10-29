#include<bits/stdc++.h>
using namespace std;
pair<int,int> bfs(int i,vector<vector<int>>&adj,int n)
{
    vector<bool> visited(n+1,false);
    vector<int> dist(n+1,0);
    queue<int> q;
    q.push(i);
    int fnode=i;
    //dist[i]=1;
    visited[i]=true;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        //if(visited[i]) continue;
        for(int adjNode:adj[f])
        {
            if(!visited[adjNode])
            {
                dist[adjNode]=dist[f]+1;
                visited[adjNode]=true;
                q.push(adjNode);
            }
            if(dist[adjNode]>dist[fnode])
            {
                fnode=adjNode;
            }
        }
    }
    return {fnode,dist[fnode]};
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int,int> one=bfs(1,adj,n);
    pair<int,int> two=bfs(one.first,adj,n);
    cout<<two.second<<endl;
}