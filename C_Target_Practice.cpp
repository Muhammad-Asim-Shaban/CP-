#include<bits/stdc++.h>
using namespace std;
int arr[10][10]={
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        int n=10;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c;
                cin>>c;
                if(c=='X')
                {
                    ans=ans+arr[i][j];
                }
            }
        }
        cout<<ans<<endl;
    }

}