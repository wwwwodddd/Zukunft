#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[3020];
int n, m, k;
int d[3020];
set<pair<int, int> > s;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		for (int j = 0; j <= k; j++) {
			a[x + j * n].push_back(make_pair(y + j * n, z));
			a[y + j * n].push_back(make_pair(x + j * n, z));
			if (j < k) {
				a[x + j * n].push_back(make_pair(y + n + j * n, z / 2));
				a[y + j * n].push_back(make_pair(x + n + j * n, z / 2));
			}
		}
	}
	for (int j = 1; j <= k; j++) {
		a[j * n].push_back(make_pair(n + j * n, 0));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	s.insert(make_pair(d[1], 1));
	while (s.size()) {
		int u = s.begin() -> second;
		s.erase(s.begin());
		for (int i = 0; i < a[u].size(); i++) {
			if (d[a[u][i].first] > d[u] + a[u][i].second) {
				s.erase(make_pair(d[a[u][i].first], a[u][i].first));
				d[a[u][i].first] = d[u] + a[u][i].second;
				s.insert(make_pair(d[a[u][i].first], a[u][i].first));
			}
		}
	}
	printf("%d\n", d[n + k * n]);
	return 0;
}