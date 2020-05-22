#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, p = 1000000007;
long long f[42][1 << 17];
long long ans = 1;
int main() {
	scanf("%d%d%d%d", &n, &x, &y, &z);
	f[0][0] = 1;
	int b = (1 << (x + y + z - 1)) | (1 << (y + z - 1)) | (1 << (z - 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 << (x + y + z); j++) {
			if (f[i][j]) {
				for (int k = 1; k <= 10; k++) {
					int l = ((j << k) | (1 << (k - 1))) % (1 << (x + y + z));
					if ((l & b) != b) {
						f[i + 1][l] = (f[i + 1][l] + f[i][j]) % p;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans = ans * 10 % p;
	}
	for (int i = 0; i < 1 << (x + y + z); i++) {
		ans = (ans + p - f[n][i]) % p;
	}
	printf("%lld\n", ans);
	return 0;
}