#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1000020];
int p[1000020];
int f[1000020][20];
int d[1000020];
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
	for (int i = 20 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main() {
	scanf("%s", s + 1);
 	n = strlen(s + 1);
	int u = 0;
	f[1][0] = 0;
	d[1] = d[0] + 1;
	for (int i = 2; i <= n; i++) {
		while (u > 0 && s[u + 1] != s[i]) {
			u = p[u];
		}
		if (s[u + 1] == s[i]) {
			u++;
		}
		p[i] = u;
		f[i][0] = u;
		d[i] = d[u] + 1;
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
}
