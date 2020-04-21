#include <bits/stdc++.h>
using namespace std;
int n, m, ss;
vector<int> a[500020];
int f[500020][20];
int d[500020];
int c[500020];
int L[500020];
int R[500020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
void dfs(int x, int y) {
	L[x] = ss;
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
	R[x] = ++ss;
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
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++) {
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == 'P') {
			change(R[x], 1);
			change(R[y], 1);
			change(R[lca(x, y)], -2);
		} else {
			if (d[x] < d[y]) {
				swap(x, y);
			}
			printf("%d\n", query(R[x]) - query(L[x]));
		}
	}
	return 0;
}