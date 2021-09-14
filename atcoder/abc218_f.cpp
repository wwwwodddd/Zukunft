#include <bits/stdc++.h>
using namespace std;
int n, m, mod = 100003;
vector<int> a[420];
queue<int> q;
int x[160000];
int y[160000];
int d[420];
int p[420];
int v[420][420];
int bfs(int x, int y) {
	memset(d, -1, sizeof d);
	d[1] = 0;
	q.push(1);
	while (q.size() > 0) {
		int u = q.front();
		q.pop();
		for (int e: a[u]) {
			if (u == x && e == y) {
				continue;
			}
			if (d[e] == -1) {
				d[e] = d[u] + 1;
				p[e] = u;
				q.push(e);
			}
		}
	}
	return d[n];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[x[i]].push_back(y[i]);
	}
	int od = bfs(-1, -1);
	for (int i = n; i > 1; i = p[i]) {
		v[p[i]][i] = 1;
	}
	for (int i = 0; i < m; i++) {
		if (v[x[i]][y[i]]) {
			printf("%d\n", bfs(x[i], y[i]));
		} else {
			printf("%d\n", od);
		}
	}
	return 0;
}