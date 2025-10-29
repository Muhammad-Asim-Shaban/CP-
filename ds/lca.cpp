#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
const int LOG=20;

vector<int> tree[N];
int up[N][LOG];
int depth[N];

void dfs(int v,int p)
{
    up[v][0]=p;
    for(int i=1;i<LOG;i++)
    {
        if(up[v][i-1]!=-1)
        {
            up[v][i]=up[up[v][i-1]][i-1];
        }
        else
        {
            up[v][i]=-1;
        }
    }
    for(int u:tree[v])
    {
        if(u!=p)
        {
            depth[u]=depth[v]+1;
            dfs(u,v);
        }
    }
}


int kthancestor(int v,int k)
{
    for(int i=0;i<LOG;i++)
    {
        if(k&(1<<i))
        {
            v=up[v][i];
            if(v==-1) break;
        }
    }
    return v;
}

int main()
{
        int n,q;
        cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    memset(up,-1,sizeof(up));
    depth[1]=0;
    dfs(1,-1);
    while(q--)
    {
        int node,k;
        cin>>node>>k;
        cout<<kthancestor(node,k)<<endl;
    }
    
}