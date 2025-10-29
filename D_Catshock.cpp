#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vector<int> visited(n+1,false);
        vector<int>parent(n+1);
        parent[1]=-1;
        visited[1]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    parent[it]=node;
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        // cout<<"parent values are"<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<parent[i]<<" ";
        // }
        vector<int>path;
        //path.push_back(n);
        int curr = n;
        while (curr != -1) 
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(),path.end()); // FIX: remove duplicate push_back(1)
        
        // cout<<"path is"<<endl;
        // for(int i=0;i<path.size();i++)
        // cout<<path[i]<<" ";
        // cout<<endl;

        vector<int>onpath(n+1,false);
        for(int x:path) onpath[x]=true;

        vector<vector<int>>ops;
        vector<int> removed;
        vector<bool>nowrem(n+1,false);

        for(int i=1;i<=n;i++)
        {
            // FIX: skip if already removed
            if(nowrem[i]) continue;

            if(!onpath[i])
            {
                int p = parent[i];
                // FIX: only destroy if parent is on main path
                if(p != -1 && onpath[p])
                {
                    ops.push_back({2,i});
                    removed.push_back(i);
                    nowrem[i]=true;
                }
            }
        }

        // FIX: Only add a move (1) if at least one 2 operation was done
        if(!ops.empty())
            ops.push_back({1,-1});

        cout<<ops.size()<<endl;
        for(int i=0;i<ops.size();i++)
        {
            vector<int> a=ops[i];
            if(a[0]==1)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<" "<<a[1]<<endl;
            }
        }
        cout<<endl;
    }
}
