#include <bits/stdc++.h>
using namespace std;
int t, n, a[60], c[60][60], p = 1000000007;
int f[60][60][60];
int main() {
	for (int i = 0; i < 55; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		memset(f, 0, sizeof f);
		f[0][0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k < n; k++) {
					f[i + 1][j][k] = (f[i + 1][j][k] + f[i][j][k]) % p;
					for (int l = 0; l < a[i] && k + l <= n - 2; l++) {
						f[i + 1][j + 1][k + l] = (f[i + 1][j + 1][k + l] + (long long)f[i][j][k] * c[k + l][l]) % p;
					}
				}
			}
		}
		printf("%d", n);
		for (int i = 2; i <= n; i++) {
			printf(" %d", f[n][i][i - 2]);
		}
		printf("\n");
	}
	return 0;
}