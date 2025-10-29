#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll check=false;
ll mst(int n,vector<pair<ll,ll>> adj[])
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> vis(n+1,0);
    pq.push({0,1});
    ll sum=0;
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int weight=it.first;
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=weight;
        //if we need mst we should add that to the list in this place.
        for(auto it: adj[node])
        {
            int adjNode=it.first;
            int edgWeight=it.second;
            if(!vis[adjNode])
            {
                pq.push({edgWeight,adjNode});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=0)
        {
            continue;
        }
        else
        {
            check=true;
            break;
        }
    }
    return sum;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n+1];
    while(m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }    
    ll ans=mst(n,adj);
    if(check==true)
    cout<<"IMPOSSIBLE"<<endl;
    else
    cout<<ans<<endl;
}