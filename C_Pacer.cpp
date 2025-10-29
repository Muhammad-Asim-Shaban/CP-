#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        long long p = 0, ans = 0;
        int q = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            long long d = x[i] - p;
            int r = q ^ y[i];
            if (d < r) {
                ok = false;
                break;
            }
            if ((d % 2) == r) ans += d;
            else ans += d - 1;
            p = x[i];
            q = y[i];
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        ans += m - p;
        cout << ans << '\n';
    }
}
