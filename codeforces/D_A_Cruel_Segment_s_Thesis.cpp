#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> seg(n);
        ll base = 0;
        for (int i = 0; i < n; ++i) {
            cin >> seg[i].first >> seg[i].second;
            base += seg[i].second - seg[i].first;
        }

        int m = n / 2;
        if (m == 0) { 
            cout << base << '\n';
            continue;
        }

        sort(seg.begin(), seg.end()); 
        vector<ll> pref(n, -1);
        priority_queue<ll> pq;
        ll sumL = 0;
        for (int i = 0; i < n; ++i) {
            pq.push(seg[i].first);
            sumL += seg[i].first;
            if ((int)pq.size() > m) {
                sumL -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == m) pref[i] = sumL;
        }

        vector<ll> suf(n, -1);
        priority_queue<ll, vector<ll>, greater<ll>> pq2; 
        ll sumR = 0;
        for (int i = n - 1; i >= 0; --i) {
            pq2.push(seg[i].second);
            sumR += seg[i].second;
            if ((int)pq2.size() > m) {
                sumR -= pq2.top();
                pq2.pop();
            }
            if ((int)pq2.size() == m) suf[i] = sumR;
        }

        ll bestAdd = 0;
        for (int i = 0; i + 1 < n; ++i) {
            if (pref[i] >= 0 && suf[i + 1] >= 0) {
                bestAdd = max(bestAdd, suf[i + 1] - pref[i]);
            }
        }

        cout << (base + bestAdd) << '\n';
    }
    return 0;
}
