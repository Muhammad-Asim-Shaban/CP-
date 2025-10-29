#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<int> seg;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n=1; while(n<_n) n<<=1;
        seg.assign(2*n, 0);
    }
    void update(int p, int val){
        p = p - 1 + n;
        seg[p] = max(seg[p], val);
        for(p >>= 1; p; p >>= 1) seg[p] = max(seg[p<<1], seg[p<<1|1]);
    }
    int query(int l, int r){
        if(l>r) return 0;
        int L = l - 1 + n, R = r - 1 + n;
        int res = 0;
        while(L <= R){
            if(L & 1) res = max(res, seg[L++]);
            if(!(R & 1)) res = max(res, seg[R--]);
            L >>= 1; R >>= 1;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<int> a(n+1), b(n+1);
        int maxVal = 0;
        for(int i=1;i<=n;i++){ cin >> a[i]; maxVal = max(maxVal, a[i]); }
        for(int i=1;i<=n;i++){ cin >> b[i]; maxVal = max(maxVal, b[i]); }
        int V = max(2*n, maxVal);

        vector<int> prev_ge(n+1, 0);
        {
            vector<int> st;
            for(int i=1;i<=n;i++){
                while(!st.empty() && a[st.back()] < a[i]) st.pop_back();
                prev_ge[i] = st.empty() ? 0 : st.back();
                st.push_back(i);
            }
        }

        SegTree seg(V+5);
        ll ans = 0;
        for(int i=1;i<=n;i++){
            int last_ge_b = seg.query(b[i], V);
            ll factor = (ll)(n - i + 1);
            ll add = 0;
            if(b[i] == a[i]){
                add += (ll)(i - prev_ge[i]);
            }
            add += (ll)min(prev_ge[i], last_ge_b);
            ans += add * factor;
            seg.update(a[i], i);
        }
        cout << ans << '\n';
    }
    return 0;
}
