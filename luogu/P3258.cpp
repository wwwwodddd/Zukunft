#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[300020];
int b[300020];
int f[300020][19];
int d[300020];
int s[300020];
int ans;
void dfs(int x, int y) {
	f[x][0] = y;
	d[x] = d[y] + 1;
	for (int i = 1; i < 19; i++) {
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i: a[x]) {
		if (i != y) {
			dfs(i, x);
		}
	}
}
void dfs2(int x, int y) {
	for (int i: a[x]) {
		if (i != y) {
			dfs2(i, x);
			s[x] += s[i];
		}
	}
}
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 19; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 19 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++) {
		int l = lca(b[i-1], b[i]);
		s[b[i-1]]++;
		s[f[b[i]][0]]++;
		s[l]--;
		s[f[l][0]]--;
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", s[i]);
	}
	return 0;
}