#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> transform_once(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> cnt(n + 2, 0);
    for (int x : a) if (x <= n) cnt[x]++;
    int M = 0;
    while (cnt[M] > 0) ++M;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (x < M && cnt[x] == 1) b[i] = x;
        else b[i] = M;
    }
    return b;
}

ll sum_vec(const vector<int>& v) {
    ll s = 0;
    for (int x : v) s += x;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        if (k == 0) {
            cout << sum_vec(a) << '\n';
            continue;
        }
        auto a1 = transform_once(a);
        if (k == 1) {
            cout << sum_vec(a1) << '\n';
            continue;
        }
        auto a2 = transform_once(a1);
        if (k % 2 == 0) {
            cout << sum_vec(a2) << '\n';
        } else {
            auto a3 = transform_once(a2);
            cout << sum_vec(a3) << '\n';
        }
    }
    return 0;
}
