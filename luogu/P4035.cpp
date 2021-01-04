#include <bits/stdc++.h>
using namespace std;
int n;
double a[20][20];
double b[20][20];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lf", &b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 2 * (b[i][j] - b[n][j]);
			a[i][n] += b[i][j] * b[i][j] - b[n][j] * b[n][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int t = i;
		for (int j = i; j < n; j++) {
			if (abs(a[t][i]) < abs(a[j][i])) {
				t = j;
			}
		}
		swap(a[t], a[i]);
		double u = a[i][i];
		for (int j = 0; j <= n; j++) {
			a[i][j] /= u;
		}
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			u = a[j][i];
			for (int k = 0; k <= n; k++) {
				a[j][k] -= u * a[i][k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.3f%c", a[i][n], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}