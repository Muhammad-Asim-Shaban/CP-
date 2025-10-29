#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001];
pair<int,int> parent[1001][1001];
char moveTaken[1001][1001];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char dirChar[4] = {'U', 'D', 'L', 'R'};

bool bfs(int si, int sj, int &ei, int &ej) {
    queue<pair<int,int>> q;
    visited[si][sj] = true;
    q.push({si, sj});

    while (!q.empty()) {
        auto [f, l] = q.front();
        q.pop();

        if (grid[f][l] == 'B') {
            ei = f;
            ej = l;
            return true;  // found destination
        }

        for (int k = 0; k < 4; k++) {
            int nr = f + dr[k];
            int nc = l + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !visited[nr][nc] && grid[nr][nc] != '#') {
                visited[nr][nc] = true;
                parent[nr][nc] = {f, l};
                moveTaken[nr][nc] = dirChar[k];
                q.push({nr, nc});
            }
        }
    }
    return false;  // no path
}

int main() {
    cin >> n >> m;
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                si = i; sj = j;
            }
        }
    }

    if (!bfs(si, sj, ei, ej)) {
        cout << "NO\n";
        return 0;
    }

    // reconstruct path
    string path = "";
    int x = ei, y = ej;
    while (!(x == si && y == sj)) {
        path.push_back(moveTaken[x][y]);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}
