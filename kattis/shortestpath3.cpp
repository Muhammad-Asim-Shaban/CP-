#include<bits/stdc++.h>
using namespace std;
vector<int> bellmenford(int V,vector<vector<int>> edges,int S)
{
    vector<int> dist(V,1e8);
    dist[S]=0;
    for(int i=S;i<V-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    return dist;
}
int main()
{
    while(true)
    {
        int n,m,q,s;
        cin>>n>>m>>q>>s;
        vector<vector<int>> edges;
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vector<int>p;
            p.push_back(u);
            p.push_back(v);
            p.push_back(w);
            edges.push_back(p);
        }
        while(q--)
        {
            int a;
            cin>>a;
            vector<int> dist=bellmenford(n,edges,s);
            for(int i=0;i<n;i++)
            {
                cout<<dist[i]<<" ";
            }
        }

    }
    
}