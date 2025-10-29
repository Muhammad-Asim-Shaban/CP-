#include<bits/stdc++.h>
using namespace std;
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
    int girth=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        vector<int> dist(n+1,-1);
        queue<pair<int,int>> q;
        dist[i]=0;
        q.push({i,-1});
        while(!q.empty())
        {
            int el=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int u:adj[el])
            {
                if(dist[u]==-1)
                {
                    dist[u]=dist[el]+1;
                    q.push({u,el});
                }
                else if(parent!=u)
                {
                    girth=min(girth,dist[u]+dist[el]+1);
                }
            }
        }
    }
    if(girth==INT_MAX)
    cout<<-1<<endl;
    else
    cout<<girth<<endl;
}