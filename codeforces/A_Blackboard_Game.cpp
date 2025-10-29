#include <iostream>
#include <vector>
#include <numeric> 

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> counts(4, 0); 

    for (int i = 0; i < n; ++i) {
        counts[i % 4]++;
    }

    if (counts[0] == counts[3] && counts[1] == counts[2]) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Alice\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
