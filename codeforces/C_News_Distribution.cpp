#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> edges[500005];
ll a[500005];
bool visited[500005];
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll k;
        cin>>k;
        vector<ll>v(k);
        for(ll j=0;j<k;j++)
        {
            cin>>v[j];
            --v[j];
        }
        for(ll j=0;j+1<k;j++)
        {
            edges[v[j]].push_back(v[j+1]);
            edges[v[j+1]].push_back(v[j]);
        }
    }
    memset(visited,0,sizeof(visited));
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<ll>comp;
            queue<ll>q;
            q.push(i);
            while(!q.empty())
            {
                ll x=q.front();
                q.pop();
                if(visited[x]) continue;
                visited[x]=true;
                comp.push_back(x);
                for(ll y:edges[x])
                {
                    if(!visited[y])
                    {
                        q.push(y);
                    }
                }
            }
            for(ll x:comp)
            {
                a[x]=comp.size();
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}