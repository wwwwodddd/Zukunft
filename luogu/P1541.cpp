#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int f[42][42][42][42];
int a[400];
int c[5];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> x;
		c[x]++;
	}
	for (int i = 0; i <= c[1]; i++) {
		for (int j = 0; j <= c[2]; j++) {
			for (int k = 0; k <= c[3]; k++) {
				for (int l = 0; l <= c[4]; l++) {
					if (i > 0) {
						f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l]);
					}
					if (j > 0) {
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l]);
					}
					if (k > 0) {
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k-1][l]);
					}
					if (l > 0) {
						f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l-1]);
					}
					f[i][j][k][l] += a[i + 2 * j + 3 * k + 4 * l];
				}
			}
		}
	}
	cout << f[c[1]][c[2]][c[3]][c[4]] << endl;
	return 0;
}