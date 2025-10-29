#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> vec(n);
    bool z=false;
    int mini=INT_MAX;
    int mini2=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
        if(vec[i]==0)
        {
            z=true;break;
        }
        mini=min(mini,abs(vec[i]));
    }
    if(z) cout<<0<<endl;
    else cout<<mini<<endl;
}