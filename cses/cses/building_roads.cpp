#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> visited;
vector<vector<ll>> adj(1000005);
vector<ll>rep;
void dfs(ll node)
{
    visited[node]=true;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it);
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1,false);
    for(ll i = 0; i < m; i++)
    {
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            rep.push_back(i);
            dfs(i);
        }
    }
    cout<<rep.size()-1<<endl;
    for(ll i=0;i<rep.size()-1;i++)
    {
        cout<<rep[i]<<" "<<rep[i+1]<<endl;
    }
    return 0;
}