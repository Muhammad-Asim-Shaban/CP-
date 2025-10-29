#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<ll> adj[100005];
vector<bool> vis(100005, false);
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        adj.resize(n+1);
        vis.resize(n+1,false);
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}