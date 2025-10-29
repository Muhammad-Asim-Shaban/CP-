#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;

        cin>>n;
        vector<ll> v(n);
       vector<long long> prefixMin(n), suffixMax(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
       prefixMin[0] = v[0];
        for (int j = 1; j < n; ++j)
        prefixMin[j] = min(prefixMin[j - 1], v[j]);
        suffixMax[n - 1] = v[n - 1];
        for (int j = n - 2; j >= 0; --j)
        suffixMax[j] = max(suffixMax[j + 1], v[j]);
        string ans;
        ans+="1";
        for(ll i=1;i<n-1;i++)
        {
            if(v[i]<prefixMin[i-1] || v[i]>suffixMax[i+1])
            {
                ans+="1";
            }
            else
            {
                ans+="0";
            }
        }
        ans+="1";
        cout<<ans<<endl;
    }
}