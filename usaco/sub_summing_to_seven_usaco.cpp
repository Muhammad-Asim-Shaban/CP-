#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 7;

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int cow_num;
	cin >> cow_num;

	int longest_photo = 0;
	// first[i] stores the index of the first time a prefix sum % 7 == i
	vector<int> first(MOD, -1);
	first[0] = 0;

	int curr_remainder = 0;
	for (int i = 1; i <= cow_num; i++) {
		int cow;
		cin >> cow;

		curr_remainder = (curr_remainder + cow) % MOD;
		if (first[curr_remainder] == -1) {
			first[curr_remainder] = i;
		} else {
			longest_photo = max(longest_photo, i - first[curr_remainder]);
		}
	}
	cout << longest_photo << endl;
}