#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, c, cnt;
int d[500020];
vector<pair<int, int> > a[500020];
map<int, int> g[100020];
deque<int> q;
int get(int x, int y) {
	if (g[x].count(y)) {
		return g[x][y];
	}
	return g[x][y] = ++cnt;
}
void add(int x, int y, int z) {
	a[x].push_back(make_pair(y, z));
	a[y].push_back(make_pair(x, z));
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		get(i, 0);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &c);
		int x0 = get(x, 0), xc = get(x, c);
		int y0 = get(y, 0), yc = get(y, c);
		add(xc, yc, 0);
		add(x0, yc, 1);
		add(xc, y0, 1);
	}
	memset(d, -1, sizeof d);
	d[1] = 0;
	q.push_back(1);
	while (q.size()) {
		int u = q.back();
		q.pop_back();
		for (pair<int, int> i: a[u]) {
			if (d[i.first] == -1 || d[i.first] > d[u] + i.second) {
				d[i.first] = d[u] + i.second;
				if (i.second == 1) {
					q.push_front(i.first);
				} else {
					q.push_back(i.first);
				}
			}
		}
	}
	printf("%d\n", d[n] >> 1);
	return 0;
}