#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        sort(a.begin(), a.end(), greater<long long>()); 
        
        int k = n;
        if (m < k) k = (int)m; 
        
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += a[i] * (m - i);
        }
        cout << ans << '\n';
    }
    return 0;
}
