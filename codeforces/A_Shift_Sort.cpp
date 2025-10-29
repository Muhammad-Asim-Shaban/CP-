#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int z = 0;
        for (char c : s) if (c == '0') ++z;
        int misplaced = 0;
        for (int i = 0; i < z; ++i) if (s[i] == '1') ++misplaced;
        cout << misplaced << '\n';
    }
    return 0;
}
