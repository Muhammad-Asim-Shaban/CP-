#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll M1 = 1000000007LL;
const ll M2 = 1000000009LL;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>> a(n);
        int mx=0;
        for(int i=0;i<n;i++){
            int k; cin>>k;
            a[i].resize(k);
            for(int j=0;j<k;j++) cin>>a[i][j];
            mx = max(mx, k);
        }
        vector<int> L(n);
        for(int i=0;i<n;i++) L[i]= (int)a[i].size();
        vector<vector<int>> g(mx);
        for(int i=0;i<n;i++){
            for(int s=0;s<L[i];s++) g[s].push_back(i);
        }
        ll base = 91138233LL;
        vector<ll> pw1(mx+2), pw2(mx+2);
        pw1[0]=1; pw2[0]=1;
        for(int i=1;i<=mx;i++){
            pw1[i] = (pw1[i-1]*base)%M1;
            pw2[i] = (pw2[i-1]*base)%M2;
        }
        vector<vector<ll>> p1(n), p2(n);
        for(int i=0;i<n;i++){
            int len=L[i];
            p1[i].assign(len+1,0);
            p2[i].assign(len+1,0);
            for(int j=0;j<len;j++){
                ll v = a[i][j] + 1007;
                p1[i][j+1] = (p1[i][j]*base + v) % M1;
                p2[i][j+1] = (p2[i][j]*base + v) % M2;
            }
        }
        auto geth = [&](int id,int l,int r)->pair<ll,ll>{
            ll x1 = (p1[id][r+1] - (p1[id][l]*pw1[r-l+1])%M1) % M1;
            if(x1<0) x1+=M1;
            ll x2 = (p2[id][r+1] - (p2[id][l]*pw2[r-l+1])%M2) % M2;
            if(x2<0) x2+=M2;
            return {x1,x2};
        };
        auto lesssuf = [&](int x,int y,int pos)->bool{
            int lx = L[x], ly = L[y];
            int maxL = min(lx,ly) - pos;
            int lo=0, hi=maxL;
            while(lo<hi){
                int mid = (lo+hi+1)/2;
                if(geth(x,pos,pos+mid-1)==geth(y,pos,pos+mid-1)) lo=mid;
                else hi=mid-1;
            }
            int lcp = lo;
            if(lcp==maxL) return lx < ly;
            return a[x][pos+lcp] < a[y][pos+lcp];
        };
        vector<int> res;
        int pos = 0;
        while(pos < mx){
            if(g[pos].empty()) break;
            int bst = g[pos][0];
            for(size_t ii=1; ii<g[pos].size(); ++ii){
                int id = g[pos][ii];
                if(lesssuf(id, bst, pos)) bst = id;
            }
            for(int t=pos; t<L[bst]; ++t) res.push_back(a[bst][t]);
            pos = L[bst];
        }
        for(size_t i=0;i<res.size();++i){
            if(i) cout<<' ';
            cout<<res[i];
        }
        cout<<"\n";
    }
    return 0;
}
