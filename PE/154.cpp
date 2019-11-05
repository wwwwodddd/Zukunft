#include <bits/stdc++.h>
using namespace std;
int f[200020];
int g[200020];
int main() {
	int n = 200000;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i / 2] + i / 2;
		g[i] = g[i / 5] + i / 5;
	}
	long long z = 0;
	for (int i = 0; i <= n; i++) {
		if (i % 1000 == 0) {
			fprintf(stderr, "%d\n", i);
		}
		for (int j = 0; i + j <= n; j++) {
			if (f[n] - f[i] - f[j] - f[n - i - j] >= 12 && g[n] - g[i] - g[j] - g[n - i - j] >= 12) {
				z++;
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}
