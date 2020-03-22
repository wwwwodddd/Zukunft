#include <bits/stdc++.h>
using namespace std;
int t, n, m, p = 10000;
int f[10020];
int pw(int x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= 10000; i++) {
			f[i] = (f[i - 1] + pw(i, m)) % p;
		}
		printf("%d\n", (f[10000] * (n / 10000) + f[n % 10000]) % p);
	}
	return 0;
}