#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[21][1048577];
int g[21][1048577];
char s[1048577];
int zi, zj;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%s", s);
		for (int j = 0; j < 1 << i; j++) {
			f[i][j] = s[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 1 << i; j++) {
			int p = i - 1, b = (j >> (i - 1)) & 1;
			while (p >= 0 &&  b == ((j >> p) & 1)) {
				p--;
			}
			g[i][j] = p;
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; i + j <= n; j++) {
			for (int k = 0; k < 1 << (i + j); k++) {
				f[i][k >> j] += f[i + j][k];
				int p = g[j][k & ((1 << j) - 1)];
				if (p >= 0) {
					f[i + p + 1][(k & ((1 << (p + 1)) - 1)) | (k >> j << (p + 1))] += f[i + j][k];
				}
			}
		}
		for (int j = (1 << i) - 1; j >= 0; j--) {
			if (f[i][j] >= m) {
				zi = i;
				zj = j;
			}
		}
	}
	for (int i = zi - 1; i >= 0; i--) {
		printf("%d", zj >> i & 1);
	}
	printf("\n");
	return 0;
}