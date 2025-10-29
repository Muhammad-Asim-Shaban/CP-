#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> dp;
int solve(int s)
{
    if (s == 0) return 0; // base case
    if (dp[s] != -1) return dp[s]; // already computed

    dp[s] = INT_MAX; // initialize with large value
    int temp = s;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit > 0) 
        {
            dp[s] = min(dp[s], 1 + solve(s - digit));
        }
        temp /= 10;
    }
    return dp[s];
}


int main()
{
    cin>>n;
    dp.resize(n+1);
    fill(dp.begin(), dp.end(), -1);
    dp[0]=0;
    cout<<solve(n)<<endl;
}