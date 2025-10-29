#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + vec[i - 1];
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << "\n";
    }
}
