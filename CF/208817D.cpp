#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int g[120][120];
double d[120][120];
bool gao() {
	memset(d, 0, sizeof d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] != -1) {
				d[i][j] = 1;
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {
					d[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i][i]) {
			return false;
		}
	}
	return true;
}
bool ok(double M) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] > 0) {
				d[i][j] = log(g[i][j]) - M;
			} else {
				d[i][j] = -1e99;
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = max(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i][i] > 0) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(g, -1, sizeof g);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = max(g[x][y], z);
	}
	if (gao()) {
		printf("-1\n");
	} else {
		double L = -1;
		double R = 20;
		for (int i = 0; i < 80; i++) {
			double M = (L + R) / 2;
			if (ok(M)) {
				L = M;
			} else {
				R = M;
			}
		}
		if (L < 0) {
			printf("0\n");
		} else {
			printf("%.8f\n", exp(L));
		}
	}
	return 0;
}