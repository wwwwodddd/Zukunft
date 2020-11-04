#include <bits/stdc++.h>
using namespace std;
long long f[33][33][33];
long long g[33][33][33];
int t, a, b, c;
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d%d", &a, &b, &c);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		f[0][0][0] = 1;
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				for (int k = 0; k < 31; k++) {
					if (c >> i & 1) {
						f[i + 1][j + 1][k] += f[i][j][k];
						f[i + 1][j][k + 1] += f[i][j][k];
						f[i + 1][j][k] += g[i][j][k];
						g[i + 1][j + 1][k + 1] += g[i][j][k];
					} else {
						g[i + 1][j + 1][k + 1] += f[i][j][k];
						f[i + 1][j][k] += f[i][j][k];
						g[i + 1][j + 1][k] += g[i][j][k];
						g[i + 1][j][k + 1] += g[i][j][k];
					}
				}
			}
		}
		int cnta = __builtin_popcount(a);
		int cntb = __builtin_popcount(b);
		printf("%lld\n", f[31][cnta][cntb]);
	}
	return 0;
}