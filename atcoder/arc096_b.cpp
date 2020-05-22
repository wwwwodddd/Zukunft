#include <bits/stdc++.h>
using namespace std;
int n;
long long c, z;
long long a[100020];
long long b[100020];
long long f[100020];
long long g[100020];
long long p[100020];
long long q[100020];
int main() {
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &p[i], &a[i]);
		q[i] = c - p[i];
		b[i] = a[i];
		a[i] += a[i - 1];
		f[i] = max(f[i - 1], a[i] - 2 * p[i]);
	}
	for (int i = n; i >= 1; i--) {
		b[i] += b[i + 1];
		g[i] = max(g[i + 1], b[i] - 2 * q[i]);
	}
	for (int i = 1; i <= n; i++) {
		z = max(z, a[i] - p[i] + g[i + 1]);
		z = max(z, b[i] - q[i] + f[i - 1]);
	}
	printf("%lld\n", z);
	return 0;
}