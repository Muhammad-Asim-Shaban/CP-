#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> color(n + 1, 0); // 0: uncolored, 1: Team 1, 2: Team 2
    bool possible = true;

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) { // If uncolored, start BFS from here
            std::queue<int> q;
            q.push(i);
            color[i] = 1; // Assign to Team 1

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == 0) { // Uncolored neighbor
                        color[v] = 3 - color[u]; // Assign opposite team
                        q.push(v);
                    } else if (color[v] == color[u]) { // Same team as friend
                        possible = false;
                        break; // Not bipartite
                    }
                }
                if (!possible) break;
            }
        }
        if (!possible) break;
    }

    if (possible) {
        for (int i = 1; i <= n; ++i) {
            std::cout << color[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }

    return 0;
}
