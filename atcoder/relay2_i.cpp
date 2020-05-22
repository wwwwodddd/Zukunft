#include <bits/stdc++.h>
using namespace std;
int n, m, a[120], b[120], p = 1000000007;
int c[32777], d[32777], t[120];
long long f[2][32777], z;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = t[0] = 1; i <= 105; i++) {
		t[i] = t[i - 1] * 2 % p;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--;
		b[i]--;
	}
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i >> a[j] & 1) & (i >> b[j] & 1)) {
				c[i]++;
			}
			if ((i >> a[j] & 1) | (i >> b[j] & 1)) {
				d[i]++;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 1 << n; j++) {
			if (~j >> i & 1) {
				continue;
			}
			f[i][j] = t[c[j]];
			for (int k = j; k > 0; k = (k - 1) & j) {
				f[i][j] = (f[i][j] + p - f[i][j - k] * t[c[k]]) % p;
			}
		}
	}
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			if ((i & j) || c[i] + c[j] != c[i | j]) {
				continue;
			}
			z = (z + f[0][i] * f[1][j] % p * t[m - d[i | j]]) % p;
		}
	}
	printf("%d\n", (t[m] + p - z) % p);
	return 0;
}