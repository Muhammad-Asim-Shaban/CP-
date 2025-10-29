#include<bits/stdc++.h>
using namespace std;
vector<int> parent,Rank,len;
int com,lcom;
int find(int x)    //it will find the parent of a provided element (x)
{
    while(x!=parent[x])
    {
        x=find(parent[x]);   //path compression.
    }
    return parent[x];
}

void merge(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
    {
       if(Rank[px]>Rank[py])
       {
            parent[py]=px;
            len[px]+=len[py];
       }
       else if(Rank[py]>Rank[px])
       {
            parent[px]=py;
            len[py]+=len[px];
       }
       else
       {
            parent[px]=py;
            Rank[py]++;
            len[py]+=len[px];
       }
       com--;
       lcom=max(lcom,max(len[px],len[py]));
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    Rank.resize(n+1,0);
    len.resize(n+1,1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    com=n;
    lcom=1;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        merge(u,v);
        cout<<com<<" "<<lcom<<endl;
    }
}