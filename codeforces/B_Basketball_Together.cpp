#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    ll left=-1;
    ll right=n-1;
    ll ts=1;
    ll teams=0;
    while(left<right)
    {
        if((a[right]*ts)<=d&&left<right)
        {
            left++;ts++;
        }
        else
        {
            teams++;
            right--;
            ts=1;
        }
    }
    cout<<teams<<endl;
}