#include <bits/stdc++.h>
using namespace std;
long long a[2][2], b[2][2];
long long n, k, p;
long long mul(long long x, long long y) {
	long long re = 0;
	for (; y; y >>= 3) {
		re = (re + x * (y & 7)) % p;
		x = (x << 3) % p;
	}
	return re;
}
void mul(long long a[2][2], long long b[2][2]) {
	long long w[2][2] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				w[i][j] += mul(a[i][k], b[k][j]);
				if (w[i][j] >= p) {
					w[i][j] -= p;
				}
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		scanf("%lld%lld%lld", &n, &k, &p);
		if (n == 1) {
			printf("%lld\n", k % p);
			continue;
		}
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		a[0][1] = 1;
		b[1][0] = 1;
		b[0][1] = b[1][1] = k - 1;
		for (; n; n >>= 1) {
			if (n & 1) {
				mul(a, b);
			}
			mul(b, b);
		}
		printf("%lld\n", a[0][1]);
	}
	return 0;
}