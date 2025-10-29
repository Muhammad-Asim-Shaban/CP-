#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> bellmenford(int V,vector<vector<int>> &edges, int S)
{
    vector<int> dist(V,1e8);
    dist[S]=0;
    for(int i=0;i<V-1;i++)
    {
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=1e8 && dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
    return dist;
}





int main()
{

}