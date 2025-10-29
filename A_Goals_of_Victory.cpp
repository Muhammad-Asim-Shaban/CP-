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
        vector<int> vec;
        int sum=0;
        for(int i=0;i<n-1;i++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
            //cin>>vec[i];
            sum+=a;
        }
        cout<<-sum<<endl;
    }
}