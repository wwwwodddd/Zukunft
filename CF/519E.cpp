#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[500020];
int f[500020][20];
int d[500020];
int s[500020];
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	s[x] = 1;
	for (int i = 1; i < 20; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
			s[x] += s[i];
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
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) {
			printf("%d\n", n);
		} else if (d[x] == d[y]) {
			for (int i = 20 - 1; i >= 0; i--) {
				if (f[x][i] != f[y][i]) {
					x = f[x][i];
					y = f[y][i];
				}
			}
			printf("%d\n", n - s[x] - s[y]);
		} else {
			int dd = d[x] + d[y] - 2 * d[lca(x, y)];
			if (dd & 1) {
				printf("0\n");
			} else {
				if (d[x] < d[y]) {
					swap(x, y);
				}
				dd = dd / 2 - 1;
				for (int i = 0; i < 20; i++) {
					if (dd >> i & 1) {
						x = f[x][i];
					}
				}
				printf("%d\n", s[f[x][0]] - s[x]);
			}
		}
	}
	return 0;
}