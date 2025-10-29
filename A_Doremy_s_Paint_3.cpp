#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //int m=INT_MIN;
        vector<int> vec(n);
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            m[vec[i]]++;
        }
        if(m.size()>=3)
        {
            cout<<"No"<<endl;
            //cout<<"runs"<<endl;
            continue;
        }
        if(m.size()==2)
        {
            auto it=m.begin();
            int one=it->second;
            it++;
            int two=it->second;
            if(n%2!=0)
            {
                if(abs(one-two)==1)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }

            else
            {
                if(one==two)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }

        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}