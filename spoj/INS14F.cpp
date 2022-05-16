#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, k, p = 1000000007;
int f[1000020];
int v[1000020];
int main() {
	n = 1000000;
	v[0] = v[1] = f[0] = f[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++) {
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
	}
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &k);
		if (2 * k > n) {
			printf("%lld\n", (long long)f[n] * v[n - k] % p);
		} else {
			printf("%lld\n", (long long)f[n - 1] * v[n - k] % p * k % p);
		}
	}
	return 0;
}