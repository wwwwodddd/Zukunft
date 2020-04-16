#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > a[500020];
vector<int> b[500020];
int f[500020][20];
int d[500020];
int z[500020];
multiset<int> s[500020];
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			dfs(i.first, x);
		}
	}
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void merge(int x, int y) {
	if (s[x].size() < s[y].size()) {
		s[x].swap(s[y]);
	}
	for (int i: s[y]) {
		s[x].insert(i);
	}
	s[y].clear();
}
void dfs2(int x, int y) {
	for (pair<int, int> i: a[x]) {
		if (i.first != y) {
			dfs2(i.first, x);
			z[i.second] = s[i.first].size() > 0 ? *s[i.first].begin() : -1;
			merge(x, i.first);
		}
	}
	for (int i: b[x]) {
		if (i > 0) {
			s[x].insert(i);
		} else {
			s[x].erase(s[x].find(-i));
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++) {
		int x, y, z, l;
		scanf("%d%d%d", &x, &y, &z);
		l = lca(x, y);
		b[x].push_back(z);
		b[y].push_back(z);
		b[l].push_back(-z);
		b[l].push_back(-z);
	}
	dfs2(1, 0);
	for (int i = 1; i < n; i++) {
		printf("%d\n", z[i]);
	}
	return 0;
}