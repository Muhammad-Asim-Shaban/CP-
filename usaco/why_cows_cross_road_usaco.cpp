#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	std::ifstream read("maxcross.in");
	int n, k, b;
	read >> n >> k >> b;

	vector<int> signals(n);
	for (int i = 0; i < b; i++) {
		int index;
		read >> index;
		signals[index - 1] += 1;
	}

	vector<int> pref_sum(n + 1);
	for (int i = 0; i < n; i++) { pref_sum[i + 1] = signals[i] + pref_sum[i]; }

	int min_repair = n;
	for (int i = 0; i <= n - k; i++) {
		min_repair = std::min(min_repair, pref_sum[i + k] - pref_sum[i]);
	}

	std::ofstream("maxcross.out") << min_repair << endl;
}