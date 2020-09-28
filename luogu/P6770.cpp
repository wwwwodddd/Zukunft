#include <bits/stdc++.h>
using namespace std;
int n, m, l, t;
vector<pair<int, int> > a[100020];
priority_queue<pair<int, int> > q;
int d[100020];
int s[100020], sc;
int main() {
	scanf("%d%d%d%d", &n, &m, &l, &t);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	q.push(make_pair(-d[1], 1));
	while (q.size() > 0) {
		pair<int, int> u = q.top();
		q.pop();
		if (-u.first > d[u.second]) {
			continue;
		}
		for (int i = 0; i < a[u.second].size(); i++) {
			pair<int, int> e = a[u.second][i];
			if (d[e.first] > d[u.second] + e.second) {
				d[e.first] = d[u.second] + e.second;
				q.push(make_pair(-d[e.first], e.first));
			}
		}
	}
	for (int i = 1; i <= l; i++) {
		int x;
		scanf("%d", &x);
		if (d[x] <= t) {
			s[sc++] = i;
		}
	}
	printf("%d\n", sc);
	for (int i = 0; i < sc; i++) {
		printf("%d\n", s[i]);
	}
	return 0;
}