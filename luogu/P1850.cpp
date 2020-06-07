#include <bits/stdc++.h>
using namespace std;
double p[2020];
double f[2020][2020][2];
int n, m, v, e;
int d[320][320];
int c[2020][2];
int main() {
	scanf("%d%d%d%d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i][0]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &p[i]);
	}
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= v; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < e; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		d[x][y] = min(d[x][y], z);
		d[y][x] = min(d[y][x], z);
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j][0] = f[i][j][1] = 1e30;
		}
	}
	f[1][0][1] = 1e30;
	for (int i = 2; i <= n; i++) {
		f[i][0][0] = f[i - 1][0][0] + d[c[i - 1][0]][c[i][0]];
		for (int j = 1; j <= m; j++) {
			double d00 = d[c[i - 1][0]][c[i][0]];
			double d10 = d[c[i - 1][1]][c[i][0]];
			double d01 = d[c[i - 1][0]][c[i][1]];
			double d11 = d[c[i - 1][1]][c[i][1]];
			d11 *= p[i - 1] * p[i];
			d11 += d01 * (1 - p[i - 1]) * p[i];
			d11 += d10 * p[i - 1] * (1 - p[i]);
			d11 += d00 * (1 - p[i - 1]) * (1 - p[i]);
			d01 *= p[i];
			d01 += d00 * (1 - p[i]);
			d10 *= p[i - 1];
			d10 += d00 * (1 - p[i - 1]);
			f[i][j][0] = min(f[i - 1][j][0] + d00, f[i - 1][j][1] + d10);
			f[i][j][1] = min(f[i - 1][j - 1][0] + d01, f[i - 1][j - 1][1] + d11);
		}
	}
	printf("%.2f\n", min(f[n][m][0], f[n][m][1]));
	return 0;
}