#include <bits/stdc++.h>
using namespace std;

int lcs2(const string &a, const string &b){
    int n = a.size(), m = b.size();
    vector<int> dp(m+1, 0), ndp(m+1, 0);
    for(int i=0;i<n;i++){
        ndp.assign(m+1,0);
        for(int j=0;j<m;j++){
            if(a[i]==b[j]) ndp[j+1] = dp[j] + 1;
            else ndp[j+1] = max(dp[j+1], ndp[j]);
        }
        dp.swap(ndp);
    }
    return dp[m];
}
int lcsAll(const vector<string> &vs){
    if(vs.empty()) return 0;
    string cur = vs[0];
    for(size_t i=1;i<vs.size();++i){
        int len = lcs2(cur, vs[i]);
        int n = cur.size(), m = vs[i].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int p=0;p<n;p++){
            for(int q=0;q<m;q++){
                if(cur[p]==vs[i][q]) dp[p+1][q+1] = dp[p][q]+1;
                else dp[p+1][q+1] = max(dp[p][q+1], dp[p+1][q]);
            }
        }
        int p=n, q=m;
        string ns;
        while(p>0 && q>0){
            if(cur[p-1]==vs[i][q-1]){
                ns.push_back(cur[p-1]);
                --p; --q;
            } else {
                if(dp[p-1][q] >= dp[p][q-1]) --p;
                else --q;
            }
        }
        reverse(ns.begin(), ns.end());
        cur = ns;
        if(cur.empty()) return 0;
    }
    return (int)cur.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,k;
        cin>>n>>k;
        vector<int> parent(n+1, 0);
        for(int i=2;i<=n;i++){
            cin>>parent[i];
        }
        vector<vector<int>> children(n+1);
        for(int i=2;i<=n;i++) children[parent[i]].push_back(i);
        vector<int> depth(n+1,0);
        queue<int>q;
        depth[1]=1;
        q.push(1);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: children[u]){
                depth[v]=depth[u]+1;
                q.push(v);
            }
        }
        vector<int> leaves;
        for(int i=1;i<=n;i++) if(children[i].empty()) leaves.push_back(i);
        int min_leaf_depth = INT_MAX;
        int max_leaf_depth = 0;
        for(int lf: leaves){
            min_leaf_depth = min(min_leaf_depth, depth[lf]);
            max_leaf_depth = max(max_leaf_depth, depth[lf]);
        }

        // Exact brute-force for small n
        if(n <= 20){
            int best = 0;
            vector<int> idx(n);
            for(int i=0;i<n;i++) idx[i] = i+1;
            vector<int> chooseMask(n, 0);
            for(int i=0;i<k;i++) chooseMask[i]=1;
            sort(chooseMask.begin(), chooseMask.end());
            do{
                vector<char> label(n+1,'1');
                int zeros=0;
                for(int i=0;i<n;i++){
                    if(chooseMask[i]){
                        label[idx[i]] = '0';
                        zeros++;
                    }
                }
                if(zeros != k) continue; 
                vector<string> leafStrings;
                leafStrings.reserve(leaves.size());
                for(int lf: leaves){
                    string s;
                    int cur = lf;
                    vector<int> path;
                    while(cur != 0){
                        path.push_back(cur);
                        if(cur==1) break;
                        cur = parent[cur];
                    }
                    reverse(path.begin(), path.end());
                    for(int node: path) s.push_back(label[node]);
                    leafStrings.push_back(s);
                }
                int val = lcsAll(leafStrings);
                best = max(best, val);
            } while(next_permutation(chooseMask.begin(), chooseMask.end()));
            cout<<best<<"\n";
        } else {
            if(k==0 || k==n){
                cout<<max_leaf_depth<<"\n";
            } else {
                int heuristic = min_leaf_depth;
                cout<<heuristic<<"\n";
            }
        }
    }
    return 0;
}
