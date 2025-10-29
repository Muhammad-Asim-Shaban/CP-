#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // BFS-like frontier
    set<pair<int,int>> frontier;
    frontier.insert({0,0});

    string ans;
    ans += grid[0][0];

    // total steps = 2n-2
    for (int step = 1; step < 2*n-1; step++) {
        char best = 'z' + 1;
        set<pair<int,int>> next;

        // explore next layer
        for (auto [x,y] : frontier) {
            if (x+1 < n) best = min(best, grid[x+1][y]);
            if (y+1 < n) best = min(best, grid[x][y+1]);
        }

        // collect only cells with best char
        for (auto [x,y] : frontier) {
            if (x+1 < n && grid[x+1][y] == best)
                next.insert({x+1,y});
            if (y+1 < n && grid[x][y+1] == best)
                next.insert({x,y+1});
        }

        ans += best;
        frontier.swap(next);
    }

    cout << ans << "\n";
}
