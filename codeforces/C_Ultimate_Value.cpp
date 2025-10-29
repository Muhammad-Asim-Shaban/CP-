#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFLL = (ll)9e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        ll S = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) S += a[i];
            else S -= a[i];
        }

        ll best_same = 0;
        int firstOdd = -1, lastOdd = -1, firstEven = -1, lastEven = -1;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                if (firstOdd == -1) firstOdd = i;
                lastOdd = i;
            } else {
                if (firstEven == -1) firstEven = i;
                lastEven = i;
            }
        }
        if (firstOdd != -1 && lastOdd != -1 && lastOdd > firstOdd) best_same = max(best_same, (ll)(lastOdd - firstOdd));
        if (firstEven != -1 && lastEven != -1 && lastEven > firstEven) best_same = max(best_same, (ll)(lastEven - firstEven));

        vector<ll> pref(n+2, INFLL), suff(n+3, INFLL);

        ll cur = INFLL;
        for (int i = 1; i <= n; ++i) {
            if (i & 1) {
                cur = min(cur, 2*a[i] + (ll)i);
            }
            pref[i] = cur;
        }
        cur = INFLL;
        for (int i = n; i >= 1; --i) {
            if (i & 1) {
                cur = min(cur, 2*a[i] - (ll)i);
            }
            suff[i] = cur;
        }

        ll best_cross = -INFLL;
        for (int j = 1; j <= n; ++j) {
            if ((j & 1) == 0) { 
                if (pref[j] != INFLL) {
                    best_cross = max(best_cross, (2*a[j] + (ll)j) - pref[j]);
                }
                if (j+1 <= n && suff[j+1] != INFLL) {
                    best_cross = max(best_cross, (2*a[j] - (ll)j) - suff[j+1]);
                }
            }
        }

        ll best_gain = 0;
        if (best_same > best_gain) best_gain = best_same;
        if (best_cross > best_gain) best_gain = best_cross;
        if (best_gain < 0) best_gain = 0;

        cout << (S + best_gain) << '\n';
    }
    return 0;
}
