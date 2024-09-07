#include <bits/stdc++.h>
using namespace std;
int n, m, pb, pa1, pa2;
vector<pair<int, int> > a[100020];
set<pair<int, int> > q;
int d[100020];
void dijk(int s) {
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
}
int main() {
	scanf("%d%d%d%d%d", &m, &n, &pb, &pa1, &pa2);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dijk(pb);
	long long ba1 = d[pa1], ba2 = d[pa2];
	dijk(pa1);
	long long a1a2 = d[pa2];
	printf("%lld\n", a1a2 + min(ba1, ba2));
	return 0;
}
