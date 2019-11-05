#include <bits/stdc++.h>
using namespace std;
const int n = 21;
double g[n][n];
double f[1 << n][n];
double get(double a, double b) {
	return a + b - sqrt((a + b) * (a + b) - (100 - a - b) * (100 - a - b));
}
int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = get(i + 30, j + 30);
		}
	}
	for (int i = 0 ; i < 1 << n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				for (int k = 0; k < n; k++) {
					if (i >> k & 1) {
						continue;
					}
					f[i | (1 << k)][k] = max(f[i | (1 << k)][k], f[i][j] + g[j][k]);
				}
			}
		}
	}
	double s = 0;
	for (int i = 0; i < n; i++) {
		s = max(s, f[(1 << n) - 1][i]);
	}
	printf("%.0f\n", (40 * 21 * 2 - s) * 1000);
	return 0;
}