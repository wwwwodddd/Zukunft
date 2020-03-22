#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
vector<pair<int, int> > a[100020];
priority_queue<pair<int, int> > q;
int d[100020];
int f[100020];
int w[2020][2020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (w[x][y] == 0 || w[x][y] > z) {
			a[x].push_back(make_pair(y, z));
			w[x][y] = z;
		}
	}
	memset(d, 0x3f, sizeof d);
	d[1] = 0;
	f[1] = 1;
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
				f[e.first] = f[u.second];
				q.push(make_pair(-d[e.first], e.first));
			} else if (d[e.first] == d[u.second] + e.second) {
				f[e.first] += f[u.second];
			}
		}
	}
	if (d[n] > 1e9) {
		printf("No answer\n");
	} else {
		printf("%d %d\n", d[n], f[n]);
	}
	return 0;
}