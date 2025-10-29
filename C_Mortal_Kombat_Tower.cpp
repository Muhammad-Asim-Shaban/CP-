#include<bits/stdc++.h>
using namespace std;
int res(vector<int> vec,int i,int n,int turn)
{
    if(i>=n) return 0;
    if(turn==1)
    {
        if(vec[i]==0)
        {
            if(i+1<n&&vec[i]==0)
            {
                return 1+res(vec,i+2,n,2);
            }
            else
            {
                return res(vec,i+1,n,2);
            }
        }
        else
        {   
            if(i+1<n&&vec[i]==0)
            {
                return 1+res(vec,i+2,n,2);
            }
            else
            {
                return 1+res(vec,i+1,n,2);
            }
        }
    }
    else
    {
        if(vec[i]==1)
        {
            if(i+1<n&&vec[i]==1)
            {
                return res(vec,i+2,n,1);
            }
            else
            {
                return res(vec,i+1,n,1);
            }
        }
        else
        {
            if(i+1<n&&vec[i]==1)
            {
                return res(vec,i+2,n,1);
            }
            else
            {
                return res(vec,i+1,n,1);
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
        }
        cout<<res(vec,0,n,1)<<endl;
    }
}