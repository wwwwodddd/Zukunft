#include <bits/stdc++.h>
using namespace std;
map<vector<int>, double>g[20];
int main() {
	g[0][{16}] = 1;
	for (int i = 0; i < 16; i++) {
		for (pair<vector<int>, double> t: g[i]) {
			for (int j = 0; j < t.first.size(); j++) {
				vector<int> s;
				for (int k = 0; k < t.first.size(); k++) {
					if (j == k) {
						continue;
					}
					s.push_back(t.first[k]);
				}
				for (int k = t.first[j];;) {
					k /= 2;
					if (k == 0) {
						break;
					}
					s.push_back(k);
				}
				sort(s.begin(), s.end());
				g[i + 1][s] += t.second / t.first.size();
			}
		}
	}
	printf("%.6f\n", g[16][{}]);
	printf("%.6f\n", g[15][{1}] + g[14][{2}] + g[12][{4}] + g[8][{8}]);
	return 0;
}