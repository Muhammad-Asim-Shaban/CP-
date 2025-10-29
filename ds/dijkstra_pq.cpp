#include<bits/stdc++.h>
using namespace std;

const long long inf=1e19;
vector<long long> dijkstra(int V,vector<vector<pair<int,int>>> adj,int S)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(V,inf);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty())
    {
        auto [cost,node]=pq.top();
        pq.pop();
        if(cost>dist[node]) continue;
        for(auto [adjNode,edgW]:adj[node])
        {
            if (dist[node] + edgW < dist[adjNode])
            {
                dist[adjNode] = dist[node] + edgW;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back({b,c});
    }
    vector<long long> dist=dijkstra(n,adj,0);

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}