#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> up;
const long long LOG=30;
void build(vector<long long>&parent)
{
    long long n=parent.size();
    //base case
    up.assign(LOG,vector<long long>(n,-1));
    for(long long i=0;i<n;i++)
    {
        up[0][i]=parent[i];
    }
    for(long long i=1;i<LOG;i++)
    {
        for(long long j=0;j<n;j++)
        {
            if(up[i-1][j]!=-1)
            up[i][j]=up[i-1][up[i-1][j]];
            else
            up[i][j]=-1;
        }
    }
}
long long query(long long start,long long k)
{
    long long current=start;
    for(long long i=0;i<LOG;i++)
    {
        if(k&(1LL<<i))
        {
            if(current==-1) break;
            current=up[i][current];
        }
    }
    return current;
}
int main()
{
    long long n,q;
    cin>>n>>q;
    vector<long long> vec(n);
    //up.assign(n+1,{});
    for(long long i=0;i<n;i++)
    {
        cin>>vec[i];
        vec[i]--;
    }
    build(vec);
    while(q--)
    {
        long long a,b;
        cin>>a>>b;
        a--;
        cout<<query(a,b)+1<<endl;
    }
}