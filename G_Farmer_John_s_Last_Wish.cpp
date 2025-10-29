#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        bit.assign(n+1, 0);
    }
    void add(int idx, int delta){
        for(; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    int sum(int idx){
        int r = 0;
        for(; idx > 0; idx -= idx & -idx) r += bit[idx];
        return r;
    }
    int find_by_order(int k){
        int idx = 0;
        int bitMask = 1 << (31 - __builtin_clz(n)); 
        for(; bitMask; bitMask >>= 1){
            int nxt = idx + bitMask;
            if(nxt <= n && bit[nxt] < k){
                idx = nxt;
                k -= bit[nxt];
            }
        }
        return idx + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAXN = 200000;
    static vector<vector<int>> divisors;
    divisors.assign(MAXN+1, {});
    for(int d=1; d<=MAXN; ++d){
        for(int j=d; j<=MAXN; j+=d) divisors[j].push_back(d);
    }

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        int Dmax = n;
        vector<int> cnt(Dmax+1, 0); 
        Fenwick fw(Dmax + 2);
        fw.add(1, Dmax); 

        for(int i=1; i<=n; ++i){
            int val = a[i-1];
            for(int d : divisors[val]){
                if(d > Dmax) continue; 
                int oldc = cnt[d];
                fw.add(oldc + 1, -1);
                cnt[d] = oldc + 1;
                fw.add(oldc + 2, +1);
            }
            int sum_upto_i = fw.sum(i); 
            int freq0 = fw.sum(1);      
            if(sum_upto_i - freq0 == 0){
                cout << 0 << (i==n?'\n':' ');
            } else {
                int pos = fw.find_by_order(sum_upto_i); 
                if(pos <= 1) cout << 0 << (i==n?'\n':' ');
                else cout << (pos - 1) << (i==n?'\n':' ');
            }
        }
    }
    return 0;
}
