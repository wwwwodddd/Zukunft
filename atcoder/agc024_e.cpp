#include <bits/stdc++.h>
using namespace std;
int n, l, p, f[320][320];
int main() {
	scanf("%d%d%d", &n, &l, &p);
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < l; j++) {
			for (int k = i; k >= 0; k--) {
				if (k) {
					f[j][k - 1] = (f[j][k - 1] + f[j][k]) % p;
				} else {
					f[j + 1][i] = (f[j + 1][i] + f[j][k]) % p;
				}
				f[j][k] = f[j][k] * (k + 1LL) % p;
			}
		}
	}
	printf("%d\n", f[l][n]);
	return 0;
}