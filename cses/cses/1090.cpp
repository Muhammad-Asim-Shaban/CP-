#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    ll i = 0, j = n - 1, ans = 0;
    while (i <= j) {
        if (vec[i] + vec[j] <= w) {
            i++;
            j--;
        } else {
            j--;
        }
        ans++;
    }

    cout << ans << endl;
}
