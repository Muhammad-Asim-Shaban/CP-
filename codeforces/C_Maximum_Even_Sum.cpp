#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        
        if ((a & 1) && (b & 1)) {
            cout << (a * b + 1) << '\n';
            continue;
        }
        
        ll bb = b;
        int t = 0;
        while ((bb % 2LL) == 0) {
            bb /= 2LL;
            ++t;
        }
        
        if (t == 0) {                
            cout << -1 << '\n';
            continue;
        }
        if ((a & 1) && t == 1) {     
            cout << -1 << '\n';
            continue;
        }
        
        ll ans = a * (b / 2) + 2;
        cout << ans << '\n';
    }
    return 0;
}
