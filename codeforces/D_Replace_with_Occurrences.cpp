#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[b[i]].push_back(i);
        }

        vector<int> a(n, 0);
        int label = 1;
        bool possible = true;

        for (auto &p : groups) {
            int x = p.first;                
            auto &idxs = p.second;         
            if ((int)idxs.size() % x != 0) {
                possible = false;
                break;
            }
            for (int i = 0; i < (int)idxs.size(); i++) {
                a[idxs[i]] = label;
                if ((i + 1) % x == 0) label++;
            }
        }

        if (!possible) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
