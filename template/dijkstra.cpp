#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dijkstra(ll v,vector<pair<ll,ll>> adj[],ll s)
{
    set<pair<ll,ll>>st;
    vector<ll> dist(v,1e18);
    dist[s]=0;
    st.insert({0,s});
    while(!st.empty())
    {
        auto it=*(st.begin());
        ll cost=it.first;
        ll node=it.second;
        st.erase(it);
        for(auto it:adj[node])
        {
            ll adjNode=it.first;
            ll edgW=it.second;
            if(cost+edgW<dist[adjNode])
            {
                if(dist[adjNode]!=1e9)
                {
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=cost+edgW;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>> adj[n];
    while(m--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
    }
    vector<long long> dist=dijkstra(n,adj,0);
    for(long long i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}