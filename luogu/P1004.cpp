#include <bits/stdc++.h>
using namespace std;
int f[20][20][20];
int a[20][20];
int n, x, y, z;
int main() {
	scanf("%d", &n);
	while (true) {
		scanf("%d%d%d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0) {
			break;
		}
		a[x][y] = z;
	}
	for (int l = 2; l <= n+n; l++) {
		for (int i = 1; i <= n && i < l; i++) {
			for (int j = i; j <= n && j < l; j++) {
				f[l][i][j] = max(max(f[l-1][i][j], f[l-1][i][j-1]), max(f[l-1][i-1][j], f[l-1][i-1][j-1])) + a[i][l-i] + a[j][l-j];
				if (i == j) {
					f[l][i][j] -= a[i][l - i];
				}
			}
		}
	}
	printf("%d\n", f[n+n][n][n]);
	return 0;
}