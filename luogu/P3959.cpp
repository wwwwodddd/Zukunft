#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int g[13][13];
long long d[4097][4097];
long long f[13][4097];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--;
		y--;
		g[x][y] = min(g[x][y], z);
		g[y][x] = min(g[y][x], z);
	}
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			d[i][j] = 1e9;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[1 << i][1 << j] = g[i][j];
		}
	}
	for (int i = 1; i < 1 << n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				continue;
			}
			int lbi = i & -i;
			if (i == lbi) {
				continue;
			}
			d[i][1 << j] = min(d[lbi][1 << j], d[i - lbi][1 << j]);
		}
	}
	for (int i = 1; i < 1 << n; i++) {
		for (int j = 1; j < 1 << n; j++) {
			if (i & j) {
				continue;
			}
			int lbj = j & -j;
			if (j == lbj) {
				continue;
			}
			d[i][j] = d[i][j - lbj] + d[i][lbj];
		}
	}
	long long ans = 1e18;
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) {
		f[1][1 << i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			int l = (1 << n) - 1 - j;
			for (int k = l; k > 0; k = (k - 1) & l) {
				f[i + 1][j | k] = min(f[i + 1][j | k], f[i][j] + d[j][k] * i);
			}
		}
		ans = min(ans, f[i][(1 << n) - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}