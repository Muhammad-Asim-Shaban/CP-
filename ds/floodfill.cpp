#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
const int MAXM=10005;
int n,m;
char grid[MAXN][MAXM];
bool visited[MAXN][MAXM];
int currentsize=0;
void floodfill(int r,int c,char color)
{
    if(r<0||r>=n||c<0||c>=m) return;
    if(visited[r][c]) return;
    if(grid[r][c]!=color) return;
    visited[r][c]=true;
    currentsize++;
    floodfill(r-1,c,color);
    floodfill(r+1,c,color);
    floodfill(r,c-1,color);
    floodfill(r,c+1,color);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int total=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j]&&grid[i][j]=='.')
            {
                currentsize=0;
                floodfill(i,j,'.');
                total++;
            }
        }
    }
    cout<<total<<endl;
}
