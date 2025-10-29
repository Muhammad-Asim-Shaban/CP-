#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int S) {
    vector<ll> dist(n+1, INF);
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    //priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (cost > dist[node]) continue; // outdated state

        for (auto [adjNode, edgw] : adj[node]) {
            if (dist[node] + edgw < dist[adjNode]) {
                dist[adjNode] = dist[node] + edgw;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << "\n";
        return;
    }

    vector<int> path;
    int node = n;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(S);
    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // If graph is undirected: adj[b].push_back({a, c});
    }

    dijkstra(n, adj, 1);
}
