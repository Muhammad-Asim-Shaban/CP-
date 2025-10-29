#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e18;
    vector<vector<long long>> matrix(n, vector<long long>(n, INF));

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--; b--;

        // if multiple edges exist, keep the smallest
        matrix[a][b] = min(matrix[a][b], c);
        matrix[b][a] = min(matrix[b][a], c);
    }

    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (matrix[l][r] >= INF) cout << -1 << "\n";
        else cout << matrix[l][r] << "\n";
    }
}
