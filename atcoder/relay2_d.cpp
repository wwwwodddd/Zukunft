#include <bits/stdc++.h>
using namespace std;
int f[100020];
long long n, m, x, y, z1, z2, z;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		f[F(x)] = F(y);
	}
	for (int i = 1; i <= n; i++) {
		if (F(i) == F(1)) {
			z1++;
		}
		if (F(i) == F(2)) {
			z2++;
		}
	}
	z = min(z1, z2);
	printf("%lld\n", n * (n - 1) / 2 - z * (n - z) - m);
	return 0;
}