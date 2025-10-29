#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        // Construct q[i] = n+1 - p[i]
        for (int i = 0; i < n; ++i) {
            int qi = (n + 1) - p[i];
            cout << qi << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
