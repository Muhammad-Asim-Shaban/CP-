#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,b;
        cin>>n>>r>>b;
        string s;
        int lofr=r/(b+1);
        int exr=r%(b+1);
        for(int times=1;times<=b+1;times++)
        {
            for(int i=0;i<lofr;i++)
            {
                s+='R';
            }
            if(exr>0)
            {
                s+='R';
                exr--;
            }
            if(times!=b+1)
            s+='B';
        }
        cout<<s<<endl;
    }
}