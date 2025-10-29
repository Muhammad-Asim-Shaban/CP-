#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> apar(n),siz(m);
    for(int i=0;i<n;i++)
    cin>>apar[i];
    for(int i=0;i<m;i++)
    cin>>siz[i];
    int ans=0;
    int n1=0,m1=0;
    sort(apar.begin(),apar.end());
    sort(siz.begin(),siz.end());
    while(n1<=n-1&&m1<=m-1)
    {

        int a=apar[n1]-k;
        int b=apar[n1]+k;
        if(siz[m1]>=a&&siz[m1]<=b)
        {
            ans++;
            n1++;m1++;
        }
        else if(siz[m1]<a)
        {
            m1++;
        }
        else if(siz[m1]>a)
        {
            n1++;
        }
    }
    cout<<ans<<endl;
}