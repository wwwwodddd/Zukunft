#include <bits/stdc++.h>
using namespace std;
int n;
double a[120][120];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> a[i][j];
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
		if (fabs(u) < 1e-6) {
			printf("No Solution\n");
			return 0;
		}
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
		printf("%.2f\n", a[i][n]);
	}
	return 0;
}