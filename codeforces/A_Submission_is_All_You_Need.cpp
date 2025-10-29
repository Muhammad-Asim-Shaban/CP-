#include <iostream>
#include <vector>
#include <numeric>  
#include <algorithm> 

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> counts(51, 0); 
    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        int s_val;
        std::cin >> s_val;
        counts[s_val]++;
        total_sum += s_val;
    }

    long long max_score = total_sum; 
    for (int k = 1; k <= 51; ++k) {
        bool possible_mex_k = true;
        for (int i = 0; i < k; ++i) {
            if (counts[i] == 0) {
                possible_mex_k = false;
                break;
            }
        }

        if (possible_mex_k) {
            long long current_score = k; 
            long long sum_after_mex_elements = total_sum;

            for (int i = 0; i < k; ++i) {
                sum_after_mex_elements -= i;
            }
            
            max_score = std::max(max_score, current_score + sum_after_mex_elements);
        } else {
            break; 
        }
    }

    std::cout << max_score << std::endl;
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