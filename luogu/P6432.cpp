#include <bits/stdc++.h>
using namespace std;
int n;
int c[1020];
int xl[1020];
int xr[1020];
int yl[1020];
int yr[1020];
int a[2020][2020];
int f[2020][2020];
int z[2020];
int xx[2020], xc;
int yy[2020], yc;
int F(int x, int y) {
	return f[x][y] != y ? f[x][y] = F(x, f[x][y]) : y;
}
int main() {
	xl[0] = 0;
	yl[0] = 0;
	c[0] = 1;
	scanf("%d%d%d", &xr[0], &yr[0], &n);
	xx[xc++] = xl[0];
	xx[xc++] = xr[0];
	yy[yc++] = yl[0];
	yy[yc++] = yr[0];
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i], &c[i]);
		xx[xc++] = xl[i];
		xx[xc++] = xr[i];
		yy[yc++] = yl[i];
		yy[yc++] = yr[i];
	}
	sort(xx, xx + xc);
	sort(yy, yy + yc);
	xc = unique(xx, xx + xc) - xx;
	yc = unique(yy, yy + yc) - yy;
	for (int i = 0; i <= n; i++) {
		xl[i] = lower_bound(xx, xx + xc, xl[i]) - xx;
		xr[i] = lower_bound(xx, xx + xc, xr[i]) - xx;
		yl[i] = lower_bound(yy, yy + yc, yl[i]) - yy;
		yr[i] = lower_bound(yy, yy + yc, yr[i]) - yy;
	}
	for (int i = 0; i < 2 * xc; i++) {
		for (int j = 0; j <= 2 * yc; j++) {
			f[i][j] = j;
		}
	}
	for (int i = n; i >= 0; i--) {
		for (int j = xl[i]; j < xr[i]; j++) {
			for (int k = F(j, yl[i]); k < yr[i]; k = F(j, k)) {
				a[j][k] = c[i];
				z[c[i]] += (xx[j+1] - xx[j]) * (yy[k+1] - yy[k]);
				f[j][k] = k + 1;
			}
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		if (z[i] > 0) {
			printf("%d %d\n", i, z[i]);
		}
	}
	return 0;
}