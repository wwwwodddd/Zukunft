#include <bits/stdc++.h>
using namespace std;
int n, m, s;
pair<int, int> f[1000020][20];
int lg[1000020];
int d[500020];
int p[500020];
int ss;
struct Edge {
	int next;
	int to;
} e[1000020];
int h[500020], tot;
void add(int x, int y) {
	tot++;
	e[tot].next = h[x];
	e[tot].to = y;
	h[x] = tot;
}
void dfs(int x, int y) {
	d[x] = d[y] + 1;
	f[++ss][0] = make_pair(d[x], x);
	p[x] = ss;
	for (int ii = h[x]; ii > 0; ii = e[ii].next) {
		int i = e[ii].to;
		if (i != y) {
			dfs(i, x);
			f[++ss][0] = make_pair(d[x], x);
		}
	}
}
int lca(int x, int y) {
	int l = p[x], r = p[y];
	if (l > r) {
		swap(l, r);
	}
	int b = lg[r - l + 1];
	return min(f[l][b], f[r - (1 << b) + 1][b]).second;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(s, 0);
	for (int j = 1; 1 << j <= ss; j++) {
		for (int i = 1; i + (1 << j) - 1 <= ss; i++) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= ss; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}