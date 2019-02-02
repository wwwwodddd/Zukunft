#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[10020];
int n, m, t;
int c[10020];
int d[10020];
int f[10020];
set<pair<int, int> > s;
vector<int> q;
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	s.insert(make_pair(d[1], 1));
	while (s.size()) {
		int u = s.begin() -> second;
		q.push_back(u);
		s.erase(s.begin());
		for (int i = 0; i < a[u].size(); i++) {
			if (d[a[u][i].first] > d[u] + a[u][i].second) {
				s.erase(make_pair(d[a[u][i].first], a[u][i].first));
				d[a[u][i].first] = d[u] + a[u][i].second;
				f[a[u][i].first] = u;
				s.insert(make_pair(d[a[u][i].first], a[u][i].first));
			} else if (d[a[u][i].first] == d[u] + a[u][i].second) {
				f[a[u][i].first] = min(f[a[u][i].first], u);
			}
		}
	}
	long long ans = 0;
	for (int i = q.size() - 1; i > 0; i--) {
		ans = max(ans, (long long)c[q[i]] * (d[q[i]] - t));
		c[f[q[i]]] += c[q[i]];
	}
	printf("%lld\n", ans);
	return 0;
}