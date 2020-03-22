#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int main() {
	while (true) {
		int o, x, y;
		scanf("%d", &o);
		if (o == 1) {
			scanf("%d%d", &x, &y);
			if (g.find(y) == g.end()) {
				g[y] = x;
			}
		} else if (o == 2) {
			if (g.size() > 0) {
				g.erase(--g.end());
			}
		} else if (o == 3) {
			if (g.size() > 0) {
				g.erase(g.begin());
			}
		} else {
			break;
		}
	}
	long long s1 = 0;
	long long s2 = 0;
	for (map<int, int>::iterator it = g.begin(); it != g.end(); it++) {
		s1 += it->first;
		s2 += it->second;
	}
	cout << s2 << ' ' << s1 << endl;
	return 0;
}