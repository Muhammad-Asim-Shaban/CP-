#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> events;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1});  
        events.push_back({b, -1}); 
    }
    sort(events.begin(), events.end(), [](auto &x, auto &y) {
        if (x.first == y.first) return x.second > y.second;
        return x.first < y.first;
    });
    cout<<"after sorting"<<endl;
    for(int i=0;i<(events.size( ));i++)
    {
        cout<<events[i].first<<" "<<events[i].second<<endl;;
    }
    cout<<endl;


    int cur = 0, ans = 0;
    for (auto &e : events) {
        cur += e.second;
        ans = max(ans, cur);
    }
    
    cout << ans << "\n";
    return 0;
}
