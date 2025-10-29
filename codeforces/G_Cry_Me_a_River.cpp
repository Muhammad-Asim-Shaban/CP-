#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> g[MAXN], gr[MAXN];
bool red[MAXN];
bool dp[MAXN]; // true = Cry wins, false = River wins
int outdeg[MAXN];

void propagate(int u) {
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        bool old = dp[x];
        if (red[x]) {
            dp[x] = false;
        } else if (outdeg[x] == 0) {
            dp[x] = true;
        } else {
            bool win = false;
            for (int v : g[x]) {
                if (!dp[v]) { // Cry can force River into losing state
                    win = true;
                    break;
                }
            }
            dp[x] = win;
        }
        if (dp[x] != old) {
            for (int p : gr[x]) q.push(p);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n, m, qn; cin >> n >> m >> qn;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            gr[i].clear();
            red[i] = false;
            dp[i] = false;
            outdeg[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            gr[v].push_back(u);
            outdeg[u]++;
        }

        // Toposort order
        vector<int> indeg(n+1, 0);
        for (int i = 1; i <= n; i++) for (int v : g[i]) indeg[v]++;
        queue<int> topo;
        for (int i = 1; i <= n; i++) if (indeg[i] == 0) topo.push(i);
        vector<int> order;
        while (!topo.empty()) {
            int u = topo.front(); topo.pop();
            order.push_back(u);
            for (int v : g[u]) if (--indeg[v] == 0) topo.push(v);
        }

        // Compute dp in reverse topological order
        for (int i = (int)order.size()-1; i >= 0; i--) {
            int u = order[i];
            if (outdeg[u] == 0) dp[u] = true;
            else {
                bool win = false;
                for (int v : g[u]) {
                    if (!dp[v]) { win = true; break; }
                }
                dp[u] = win;
            }
        }

        while (qn--) {
            int type, u; cin >> type >> u;
            if (type == 1) {
                red[u] = true;
                propagate(u);
            } else {
                cout << (dp[u] ? "YES\n" : "NO\n");
            }
        }
    }
}
