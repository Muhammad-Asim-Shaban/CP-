#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        while (k--) {
            x *= 2;  
        }
        cout << x << "\n";
    }
    return 0;
}
