#include<bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(long long V,vector<pair<long long,long long>> adj[],long long S)
{
    set<pair<long long,long long>> st;
    vector<long long> dist(V,1e18);
    st.insert({0,S});
    dist[S]=0;
    while(!st.empty())
    {
        auto it=*(st.begin());
        long long cost=it.first;
        long long node=it.second;
        st.erase(it);
        for(auto it:adj[node])
        {
            long long adjNode=it.first;
            long long edgW=it.second;
            if(cost+edgW<dist[adjNode])
            {
                if(dist[adjNode]!=1e9)
                st.erase({dist[adjNode],adjNode});
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
