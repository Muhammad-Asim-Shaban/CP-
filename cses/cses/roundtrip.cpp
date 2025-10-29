#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl "\n"
const int MAXN=1e5+5;
vector<int> parent(MAXN,-1);
vector<bool> visited(MAXN,false);
vector<int> adj[MAXN];
int start=-1;
int endd=-1;
bool dfs(int node,int par)
{
    visited[node]=true;
    parent[node]=par;
    for(auto next: adj[node])
    {
        if(next==par) continue;
        if(visited[next])
        {
            start=next;
            endd=node;
            return true;
        }
        if(!visited[next])
        {
            if(dfs(next,node)) return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int p=m;
    while(p--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found=false;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1))
            {
                found=true;
                break;
            }
        }
    }
    if(!found)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int> path;
        path.push_back(start);
        for(int v=endd;v!=start;v=parent[v])
        {
            path.push_back(v);
        }
        path.push_back(start);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(int i=0;i<path.size();i++)
        {
            cout<<path[i]<<" ";
        }
    }
    return 0;
}