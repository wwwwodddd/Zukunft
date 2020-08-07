#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[125000];
int y[125000];
double z[125000];
int d[502];
double a[502][502];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		d[x[i]]++;
		d[y[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		a[i][i] = 1;
	}
	a[1][0] = 1;
	for (int i = 0; i < m; i++) {
		if (x[i] != n) {
			a[y[i]][x[i]] = -1. / d[x[i]];
		}
		if (y[i] != n) {
			a[x[i]][y[i]] = -1. / d[y[i]];
		}
	}
	for (int i = 1; i <= n; i++) {
		int t = i;
		for (int j = i; j <= n; j++) {
			if (abs(a[t][i]) < abs(a[j][i])) {
				t = j;
			}
		}
		swap(a[t], a[i]);
		double u = a[i][i];
		for (int j = 0; j <= n; j++) {
			a[i][j] /= u;
		}
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			u = a[j][i];
			for (int k = 0; k <= n; k++) {
				a[j][k] -= u * a[i][k];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (x[i] != n) {
			z[i] += a[x[i]][0] / d[x[i]];
		}
		if (y[i] != n) {
			z[i] += a[y[i]][0] / d[y[i]];
		}
	}
	sort(z, z + m);
	double s = 0;
	for (int i = 0; i < m; i++) {
		s += z[i] * (m - i);
	}
	printf("%.3f\n", s);
	return 0;
}