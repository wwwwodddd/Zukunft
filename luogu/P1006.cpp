#include <bits/stdc++.h>
using namespace std;
int f[120][120][120];
int a[120][120];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int l = 3; l <= n+m-1; l++) {
		for (int i = 1; i <= n && i < l; i++) {
			for (int j = i + 1; j <= n && j < l; j++) {
				f[l][i][j] = max(max(f[l-1][i][j], f[l-1][i][j-1]), max(f[l-1][i-1][j], f[l-1][i-1][j-1])) + a[i][l-i] + a[j][l-j];
			}
		}
	}
	printf("%d\n", f[n+m-1][n-1][n]);
	return 0;
}