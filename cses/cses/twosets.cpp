#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int MOD=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        vec[i]=i+1;
        sum+=(i+1);
    }
    if(sum%2!=0)
    {
        cout<<0<<endl;
        return 0;
    }
    sum/=2;
    long long dp[n+1][sum+1];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=sum;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(vec[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-vec[i-1]]+dp[i-1][j])%mod;
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    auto modpow = [&](long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
};

int inv2 = modpow(2, MOD-2); // modular inverse of 2
cout << 1LL * dp[n][sum] * inv2 % MOD << "\n";


}