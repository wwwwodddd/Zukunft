#include <bits/stdc++.h>
using namespace std;
int f[25];
int v[100020];
int p[100020], pc;
int mod = 1000000000;
long long g[100020];
int main() {
	f[1] = 1;
	for (int i = 2;i <= 24; i++) {
		f[i] = f[i - 1] + f[i - 2];
//		printf("%d %d\n", i, f[i]);
	}

	g[0] = 1;
	for (int i = 2; i <= 100000; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= 100000; j += i) {
			v[j] = i;
		}
	}
	g[0] = 1;
	printf("%d\n", pc);
	printf("%d\n", f[24]);
	for (int i = 0; i < pc; i++) {
//		printf("%d\n", g[0]);
		for (int j = p[i]; j <= f[24]; j++) {
			g[j] += g[j - p[i]] * p[i];
			g[j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 2; i <= 24; i++) {
		ans += g[f[i]];
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}