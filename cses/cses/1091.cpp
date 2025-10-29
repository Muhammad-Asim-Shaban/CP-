#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> siz(n),p(m);
    for(int i=0;i<n;i++)
    cin>>siz[i];
    for(int i=0;i<m;i++)
    cin>>p[i];
    sort(siz.begin(),siz.end());
    for(int i=0;i<m;i++)
    {
        int e=p[i];
        for(int j=1;j<n;j++)
        {
            if(siz[j]==e)
            {
                
            }
        }
    }
}