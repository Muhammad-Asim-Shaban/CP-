#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> p;
vector<ll> dijkstra(ll n, vector<pair<ll,ll>> adj[],ll S,ll t)
{
    set<pair<int,int>> st;
    vector<ll> dist(n,1e18);
    st.insert({0,S});
    dist[S]=0;
    int memo[n];
    for(int i=0;i<n;i++)
    memo[i]=-1;
    while(!st.empty())
    {
        auto it=*(st.begin());
        int cost=it.first;
        int node=it.second;
        st.erase(it);
        for(auto it:adj[node])
        {
            int adjNode=it.first;
            int edgW=it.second;
            if(cost+edgW<dist[adjNode])
            {
                memo[adjNode]=node;
                if(dist[adjNode]!=1e18)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=cost+edgW;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        p.push_back(memo[i]);
    }
    return dist;
}
int main()
{
    ll n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<pair<ll,ll>> adj[n];
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist=dijkstra(n,adj,s,t);
    vector<ll> path;
    for(int i=t;i!=-1; i=p[i]) path.push_back(i);
    reverse(path.begin(),path.end());
    if(dist[t]==1e18)
    cout<<-1<<endl;
    else
    {
        
    cout<<dist[t]<<" "<<path.size()-1<<endl;
    for(int i=0;i+1<(int)path.size();i++)
    cout<<path[i]<<" "<<path[i+1]<<endl;
    }
    
}   