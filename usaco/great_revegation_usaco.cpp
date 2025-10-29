#include <bits/stdc++.h>
using namespace std;

int n, m, color[101];

vector<vector<int> > graph;
int main()
{
    ifstream cin("revegetate.in");
    ofstream cout("revegetate.out");

    cin >> n >> m;
    graph.resize(n+1);

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int nr = 0;
    for(int i = 1; i <= n; i++)
    {
        set<int> freecolors = {1, 2, 3, 4};
        for(auto j : graph[i])
            if(color[j] != 0)
                freecolors.erase(color[j]);
        color[i] = *freecolors.begin();
        cout << color[i];
    }
    return 0;

}