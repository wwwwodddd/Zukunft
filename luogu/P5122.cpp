#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[50020];
int n, m, k;
int d1[50020];
int d2[50020];
set<pair<int, int> > s;
void dijk(int *d) {
	for (int i = 1; i <= n; i++) {
		s.insert(make_pair(d[i], i));
	}
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
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d1, 0x3f, sizeof d1);
	d1[n] = 0;
	dijk(d1);
	memset(d2, 0x3f, sizeof d2);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		d2[x] = d1[x] - y;
	}
	dijk(d2);
	for (int i = 1; i < n; i++) {
		printf("%d\n", d1[i] >= d2[i]);
	}
}