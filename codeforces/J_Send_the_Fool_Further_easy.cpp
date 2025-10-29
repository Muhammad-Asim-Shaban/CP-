#include<bits/stdc++.h>
using namespace std;
int c,r;
int n,x,y, z,m[100][100];
void f(int p,int u,int c)
{
	r=max(r,c);
	for (int i=0;i<n;i++)
		if (i != p && m[i][u])
			f(u,i,c+m[i][u]);
}
int main()
{
	cin>>n;
	for (int i=1; i<n; i++)
	{
		cin>>x>>y>>z;
		m[x][y]=z;
		m[y][x]=z;
	}
	f(-1,0,0);
	cout<<r<<endl;
	return 0;
}