#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &state, stack<int> &st, vector<int> adj[]) {
    state[node] = 1; // visiting
    for (auto it : adj[node]) {
        if (state[it] == 0) {
            if (!dfs(it, state, st, adj)) return false; // cycle found below
        } else if (state[it] == 1) {
            // Back edge -> cycle
            return false;
        }
    }
    state[node] = 2; // finished
    st.push(node);
    return true;
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> state(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (state[i] == 0) {
            if (!dfs(i, state, st, adj)) {
                return {}; // empty means cycle
            }
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
    }
    vector<int> res = topoSort(n, adj);
    if (res.empty()) {
        cout << "Sandro fails.\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << res[i] + 1 << " ";
        }
        cout << "\n";
    }
}
