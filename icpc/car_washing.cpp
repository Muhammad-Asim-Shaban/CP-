#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int e1, e2;
        cin >> e1 >> e2;

        vector<int> w1(N+1), w2(N+1);
        for (int j = 1; j <= N; j++) cin >> w1[j];
        for (int j = 1; j <= N; j++) cin >> w2[j];

        vector<int> s1(N), s2(N); // size N, but only indices [1..N-1] used
        if (N > 1) {
            for (int j = 1; j <= N-1; j++) cin >> s1[j];
            for (int j = 1; j <= N-1; j++) cin >> s2[j];
        }

        int x1, x2;
        cin >> x1 >> x2;

        // Base case (station 1)
        int t1 = e1 + w1[1];
        int t2 = e2 + w2[1];

        // Process stations 2..N
        for (int j = 2; j <= N; j++) {
            int new_t1 = min(t1 + w1[j], t2 + s2[j-1] + w1[j]);
            int new_t2 = min(t2 + w2[j], t1 + s1[j-1] + w2[j]);
            t1 = new_t1;
            t2 = new_t2;
        }

        int ans = min(t1 + x1, t2 + x2);
        cout << ans << "\n";
    }
    return 0;
}
