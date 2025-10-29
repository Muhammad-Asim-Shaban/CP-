#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>b[i];
        vector<int> c(n+1,0);
        for(int x:b) c[x]++;
        bool ok=true;
        for(int i=1;i<=n;i++) if(c[i]%k){ ok=false; break; }
        if(!ok){ cout<<0<<"\n"; continue; }
        vector<int> d(n+1,0), f(n+1,0);
        for(int i=1;i<=n;i++) d[i]=c[i]/k;
        long long S=0;
        int L=0;
        int z=0;
        for(int R=0;R<n;R++){
            int v=b[R];
            f[v]++;
            if(f[v]==d[v]+1) z++;
            while(z>0){
                int u=b[L];
                f[u]--;
                if(f[u]==d[u]) z--;
                L++;
            }
            S += (R - L + 1);
        }
        cout<<S<<"\n";
    }
    return 0;
}
