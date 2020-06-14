#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> a[500020];
int f[500020][20];
int d[500020];
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
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
int dist(int x, int y) {
	return d[x] + d[y] - 2 * d[lca(x, y)];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = lca(a, b);
		int y = lca(c, d);
		printf("%c\n", dist(a, b) == dist(a, y) + dist(b, y) || dist(c, d) == dist(c, x) + dist(d, x) ? 'Y' : 'N');
	}
	return 0;
}