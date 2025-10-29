// #include<bits/stdc++.h>
// using namespace std;
// int mod=1e9+7;
// int rec(vector<int>&arr,int n,int m,int pos,int prev,vector<vector<long long>>& dp)
// {
//     if(pos<0)
//     {
//         return 1;
//     }
//     if(dp[pos][prev]!=-1)
//     {
//         return dp[pos][prev];
//     }long long ways = 0;

//     if (arr[pos] != 0) {
//         if (prev == 0 || abs(arr[pos] - prev) <= 1) {
//             ways = rec(arr, n, m, pos - 1, arr[pos],dp);
//         }
//     } else {
//         for (int j = 1; j <= m; j++) {
//             if (prev == 0 || abs(j - prev) <= 1) {
//                 ways = (ways + rec(arr, n, m, pos - 1, j,dp)) % mod;
//             }
//         }
//     }
//     return dp[pos][prev]= ways;
    
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++)
//     cin>>arr[i];
//     vector<vector<long long>> dp(n,vector<long long> (m+1,-1));
//     cout<<rec(arr,n,m,n-1,0,dp)% mod<<endl;;
// }

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); 

    // Base case
    if (arr[0] == 0) {
        for (int val = 1; val <= m; val++) {
            dp[0][val] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int val = 1; val <= m; val++) {
                dp[i][val] = ((long long)dp[i-1][val-1] + dp[i-1][val] + dp[i-1][val+1]) % MOD;
            }
        } else {
            int val = arr[i];
            dp[i][val] = ((long long)dp[i-1][val-1] + dp[i-1][val] + dp[i-1][val+1]) % MOD;
        }
    }
    int ans = 0;
    for (int val = 1; val <= m; val++) {
        ans = (ans + dp[n-1][val]) % MOD;
    }

    cout << ans << "\n";
}
