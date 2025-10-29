#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream cin("breedflip.in");
    ofstream cout("breedflip.out");
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    bool check=false;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        {
            check=  true;
        }
        else
        {
            if(check)
            ans++;
            check=false;
        }
    }
    cout<<ans<<endl;
}