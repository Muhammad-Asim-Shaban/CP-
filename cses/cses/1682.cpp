#include<bits/stdc++.h>
using namespace std;
void bfs(int start,int n,vector<int> adj[])
{
    vector<bool> visited(n+1,false);
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty())
    {
        int ele=q.front();
        q.pop();
        for(int u:adj[ele])
        {
            if(!visited[u])
            {
                visited[u]=true;
                q.push(u);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[n]==false)
        {
            cout<<"NO"<<endl;
            cout<<
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

}

