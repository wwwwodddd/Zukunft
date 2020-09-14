#include <bits/stdc++.h>
using namespace std;
int n, m, l;
vector<pair<int, int> > a[100020];
set<pair<int, int> > q;
int d[100020];
int e[100020];
void dijk()
{
	for (int i = 1; i <= n; i++) {
		q.insert(make_pair(d[i], i));
	}
	while (q.size() > 0) {
		pair<int, int> u = *q.begin();
		q.erase(q.begin());
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > max(d[u.second], e.second)) {
				q.erase(make_pair(d[e.first], e.first));
				d[e.first] = max(d[u.second], e.second);
				q.insert(make_pair(d[e.first], e.first));
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	dijk();
	for (int k = 0; k < l; k++) {
		memcpy(e, d, sizeof e);
		for (int i = 1; i <= n; i++) {
			for (pair<int, int> j: a[i]) {
				d[j.first] = min(d[j.first], e[i]);
			}
		}
		dijk();
	}
	if (d[n] > 1e9) {
		d[n] = -1;
	}
	printf("%d\n", d[n]);
	return 0;
}