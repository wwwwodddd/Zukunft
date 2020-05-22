#include <bits/stdc++.h>
using namespace std;
int n, p = 1000000007;
long long c[60][60];
long long f[60][120];
int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
		}
	}
	f[1][n] = f[1][n - 1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = -i; j <= i; j++) {
			if (f[i][j + n] == 0) {
				continue;
			}
			for (int a = 0; a < n; a++) {
				for (int b = 0; b < n; b++) {
					if (a + b > 0 && i + a + b <= n && (j + a - b) % 2 == 0 && abs(j) <= a + b) {
						long long &t = f[i + a + b][(j + a - b) / 2 + n];
						t = (t + f[i][j + n] * c[i + a + b][a + b] % p * c[a + b][b]) % p;
					}
				}
			}
		}
	}
	printf("%lld\n", f[n][n]);
	return 0;
}