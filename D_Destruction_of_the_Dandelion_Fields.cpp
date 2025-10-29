#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        long long p=0;
        vector<long long> q;
        for(int i=0;i<n;i++){
            long long r; cin>>r;
            if(r%2==0) p+=r;
            else q.push_back(r);
        }
        if(q.empty()){
            cout<<0<<"\n";
            continue;
        }
        sort(q.begin(), q.end(), greater<long long>());
        int u=(int(q.size())+1)/2;
        long long v=0;
        for(int i=0;i<u;i++) v+=q[i];
        cout<<p+v<<"\n";
    }
    return 0;
}
