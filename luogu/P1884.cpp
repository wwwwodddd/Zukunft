#include <bits/stdc++.h>
using namespace std;
int n;
int xl[2020];
int xr[2020];
int yl[2020];
int yr[2020];
int a[2020][2020];
int xx[2020], xc;
int yy[2020], yc;
long long ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &xl[i], &yl[i], &xr[i], &yr[i]);
		xx[xc++] = xl[i];
		xx[xc++] = xr[i];
		yy[yc++] = yl[i];
		yy[yc++] = yr[i];
	}
	sort(xx, xx + xc);
	sort(yy, yy + yc);
	xc = unique(xx, xx + xc) - xx;
	yc = unique(yy, yy + yc) - yy;
	for (int i = 0; i < n; i++) {
		xl[i] = lower_bound(xx, xx + xc, xl[i]) - xx;
		xr[i] = lower_bound(xx, xx + xc, xr[i]) - xx;
		yl[i] = lower_bound(yy, yy + yc, yl[i]) - yy;
		yr[i] = lower_bound(yy, yy + yc, yr[i]) - yy;
	}
	for (int i = 0; i < n; i++) {
		a[xl[i]][yl[i]]++;
		a[xl[i]][yr[i]]--;
		a[xr[i]][yl[i]]--;
		a[xr[i]][yr[i]]++;
	}
	for (int i = 0; i < xc; i++) {
		for (int j = 0; j < yc; j++) {
			a[i][j + 1] += a[i][j];
		}
	}
	for (int i = 0; i < xc; i++) {
		for (int j = 0; j < yc; j++) {
			a[i + 1][j] += a[i][j];
		}
	}
	for (int i = 0; i < xc - 1; i++) {
		for (int j = 0; j < yc - 1; j++) {
			if (a[i][j]) {
				ans += (long long)(xx[i + 1] - xx[i]) * (yy[j + 1] - yy[j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}