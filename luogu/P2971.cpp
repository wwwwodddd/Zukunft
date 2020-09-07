#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
int f[200020][20];
int c[200020];
int d[200020];
int g[200020];
int z[200020];
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
int dis(int x, int y) {
	return d[x] + d[y] - 2 * d[lca(x, y)];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d%d", &c[i], &x);
		a[x].push_back(i);
	}
	dfs(0, 0);
	for (int i = 1; i <= n; i++) {
		if (d[g[c[i]]] < d[i]) {
			g[c[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		z[c[i]] = max(z[c[i]], dis(i, g[c[i]]));
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", z[i]);
	}
	return 0;
}