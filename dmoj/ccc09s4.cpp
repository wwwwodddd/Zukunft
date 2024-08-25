#include <bits/stdc++.h>
using namespace std;
int n, m, l, s;
vector<pair<int, int> > a[5020];
set<pair<int, int> > q;
int d[5020];
int p[5020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(p, 0x3f, sizeof p);
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[x] = y;
	}
	scanf("%d", &s);
	memset(d, 0x3f, sizeof d);
	d[s] = 0;
	q.insert(make_pair(d[s], s));
	while (q.size() > 0) {
		pair<int, int> u = *q.begin();
		q.erase(q.begin());
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second) {
				q.erase(make_pair(d[e.first], e.first));
				d[e.first] = d[u.second] + e.second;
				q.insert(make_pair(d[e.first], e.first));
			}
		}
	}
	int z = 1e9;
	for (int i = 1; i <= n; i++) {
		z = min(z, d[i] + p[i]);
	}
	printf("%d\n", z);
	return 0;
}