#include<bits/stdc++.h>
using namespace std;
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
        cin>>vec[i];
        if(is_sorted(vec.begin(),vec.end()))
        {
            for(int i=0;i<n;i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        bool check=false;
        for(int i=0;i<n;i++)
        {
            if(vec[i]%2==0)
            {
                continue;
            }
            else
            {
                check=true;
                break;
            }
        }
        if(check==false)
        {
            for(int i=0;i<n;i++)
            {
                cout<<vec[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        else
        {
            bool check2=false;
            for(int i=0;i<n;i++)
            {
                if(vec[i]%2!=0)
                {
                    continue;
                }
                else
                {
                    check2=true;
                    break;
                }
            }
            if(check2)
            {
                sort(vec.begin(),vec.end());
                for(int i=0;i<n;i++)
                {
                    cout<<vec[i]<<" ";
                }
                cout<<endl;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    cout<<vec[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
}