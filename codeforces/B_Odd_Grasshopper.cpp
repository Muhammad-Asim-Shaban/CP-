#include<bits/stdc++.h>
using namespace std;
int main()
{
int  t;
cin>>t;
while(t--)
{
 long long x,n;
cin>>x>>n;
long long  i;
for(i=n-n%4+1;i<=n;i++)
{
if(x%2==0) x-=i;
else x+=i;
}
cout<<x<<endl;
}
return 0;
}