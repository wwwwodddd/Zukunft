#include <bits/stdc++.h>
using namespace std;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19}, mod;
int b[520], v[520], w[520], c1[520], c2[520], n, ans;
int main() {
	scanf("%d%d", &n, &mod);
	b[0] = 1;
	for (int i = 1; i <= 500; i++) {
		b[i] = b[i - 1] * 2 % mod;
	}
	for (int i = 1; i <= n; i++) {
		v[i] = i;
		for (int j = 0; j < 8; j++) {
			while (v[i] % p[j] == 0) {
				v[i] /= p[j];
				w[i] |= 1 << j;
			}
		}
	}
	for (int i = 0; i < 1 << 8; i++) {
		for (int j = 0; j < 1 << 8; j++) {
			if (i & j) {
				continue;
			}
			int t = __builtin_popcount(i | j) & 1;
			memset(c1, 0, sizeof c1);
			memset(c2, 0, sizeof c2);
			for (int k = 2; k <= n; k++) {
				if ((i & w[k]) == w[k]) {
					c1[v[k]]++;
				}
				if ((j & w[k]) == w[k]) {
					c2[v[k]]++;
				}
			}
			long long tmp = b[c1[1] + c2[1]];
			for (int k = 2; k <= n; k++) {
				tmp = tmp * (b[c1[k]] + b[c2[k]] - 1) % mod;
			}
			if (t) {
				ans += mod - tmp;
			} else {
				ans += tmp;
			}
			ans %= mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}