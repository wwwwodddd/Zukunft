#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[50020];
int f[50020][16];
int d[50020];
int s[50020];
int ans;
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 16; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
		}
	}
}
int dfs2(int x, int y) {
	int re = s[x];
	for (int i: a[x]) {
		if (i != y) {
			re += dfs2(i, x);
		}
	}
	ans = max(ans, re);
	return re;
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 16; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 16 - 1; i >= 0; i--) {
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
		int x, y;
		scanf("%d%d", &x, &y);
		int l = lca(x, y);
		s[x]++;
		s[y]++;
		s[l]--;
		s[f[l][0]]--;
	}
	dfs2(1, 0);
	printf("%d\n", ans);
	return 0;
}