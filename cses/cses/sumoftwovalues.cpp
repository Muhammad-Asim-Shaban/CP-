#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].first;   // value
        vec[i].second = i + 1; // original index (1-based)
    }

    sort(vec.begin(), vec.end());

    int l = 0, r = n - 1;
    while (l < r) {
        long long sum = 1LL * vec[l].first + vec[r].first;
        if (sum == s) {
            cout << vec[l].second << " " << vec[r].second << "\n";
            return 0;
        } else if (sum < s) {
            l++;
        } else {
            r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}
