#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int LOG=20;
int up[N][LOG];
int depth[N];
vector<int> tree[N];
void dfs(int root,int parent)
{
    up[root][0]=parent;
    for(int i=1;i<LOG;i++)
    {
        if(up[root][i-1]!=-1)
        {
            up[root][i]=up[up[root][i-1]][i-1];
        }
        else
        {
            up[root][i]=-1;
        }
    }
    for(int u:tree[root])
    {
        if(u!=parent)
        {
            depth[u]=depth[root]+1;
            dfs(u,root);
        }
    }
}
int kth(int node,int k)
{
    for(int i=0;i<LOG;i++)
    {
        if(k&(1<<i))
        {
            node=up[node][i];
            if(node==-1)
            break;
        }
    }
    return node;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q,r;
        cin>>n>>q>>r;
        for(int i=0;i<n-1;i++)
        {
            int u,v;    
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(r,-1);
        while(q--)
        {
            int node,k;
            cin>>node>>k;
            cout<<kth(node,k)<<endl;
        }
    }
}