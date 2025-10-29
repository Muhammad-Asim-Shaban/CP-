#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> adj[100005];
bool vis[100005];
ll n,m;
vector<ll>v(100005);
ll dfs(ll c)
{
    ll mn=v[c];
    vis[c]=true;
    for(ll x:adj[c])
    {
        if(!vis[x])
        {
            mn=min(mn,dfs(x));
        }
    }
    return mn;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            ans+=dfs(i);
        }
    }
    cout<<ans<<endl;
}