#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	std::ifstream read("factory.in");
	int station_num;
	read >> station_num;

	vector<int> outgoing(station_num);
	for (int w = 0; w < station_num - 1; w++) {
		int s1, s2;
		read >> s1 >> s2;
		// We actually don't care about s2 here!
		outgoing[--s1]++;
	}

	vector<int> no_outs;
	// Check all stations and see if they don't have any outgoing walkways
	for (int s = 0; s < station_num; s++) {
		if (outgoing[s] == 0) {
			// Remember, we have to output the 1-indexed stations!
			no_outs.push_back(s + 1);
		}
	}
	int root = no_outs.size() == 1 ? no_outs[0] : -1;
	std::ofstream("factory.out") << root << endl;
}