#include <bits/stdc++.h>
using namespace std;
int n, m, l, f[2020][2020], p = 1000000007, z;
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i < l; i++) {
		f[i][l - i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[i][j]) {
				for (int k = 0; k < l; k++) {
					if (i + k <= n && j + l - 1 - k <= m) {
						f[i + k][j + l - 1 - k] += f[i][j];
						f[i + k][j + l - 1 - k] %= p;
					}
				}
			}
			if (i % (l - 1) == n % (l - 1) && j % (l - 1) == m % (l - 1)) {
				z += f[i][j];
				z %= p;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}