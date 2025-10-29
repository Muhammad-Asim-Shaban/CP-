#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        unsigned long long x;
        cin >> k >> x;

        unsigned long long v = __builtin_ctzll(x);
        long long n = k - (long long)v;
        cout << n << '\n';

        if (n == 0) {
            cout << '\n';
            continue;
        }

        unsigned long long W = x >> v;          
        unsigned long long S = (W - 1) >> 1;   

        for (long long i = 1; i <= n; ++i) {
            int bit = (int)((S >> (i - 1)) & 1ULL);
            cout << (bit ? 2 : 1) << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
