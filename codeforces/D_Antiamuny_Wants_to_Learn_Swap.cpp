#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    int n, K;
    vector<vector<int>> stMin, stMax;
    vector<int> logVal;

    SparseTable(const vector<int>& a) {
        n = a.size();
        K = __lg(n) + 1;
        stMin.assign(K, vector<int>(n));
        stMax.assign(K, vector<int>(n));
        logVal.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            stMin[0][i] = stMax[0][i] = a[i];
        }

        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                stMin[k][i] = min(stMin[k-1][i], stMin[k-1][i + (1 << (k-1))]);
                stMax[k][i] = max(stMax[k-1][i], stMax[k-1][i + (1 << (k-1))]);
            }
        }

        for (int i = 2; i <= n; i++) logVal[i] = logVal[i/2] + 1;
    }

    int getMin(int l, int r) {
        int j = logVal[r - l + 1];
        return min(stMin[j][l], stMin[j][r - (1 << j) + 1]);
    }

    int getMax(int l, int r) {
        int j = logVal[r - l + 1];
        return max(stMax[j][l], stMax[j][r - (1 << j) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        SparseTable st(a);

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--; // 0-based

            int mn = st.getMin(l, r);
            int mx = st.getMax(l, r);

            if (mx - mn == r - l) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
