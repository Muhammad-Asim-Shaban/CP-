#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        long long n=a.size(),m=b.size();
        long long lcs=0;
        for(long long len=1;len<=min(n,m);len++)
        {
            for(long long i=0;i+len<=n;i++)
            {
                for(long long j=0;j+len<=m;j++)
                {
                    string exa=a.substr(i,len);
                    string exb=b.substr(j,len);
                    if(exa==exb)
                    {
                        lcs=max(lcs,len);
                    }
                }
            }
        }
        long long operations=n+m-2*lcs;
        cout<<operations<<endl;
    }
}