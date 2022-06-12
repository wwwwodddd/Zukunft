#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
int b[200020];
int f[200020][20];
int g[200020][20];
int lg[200020];
int query(int f[200020][20], int l, int r) {
	if (l > r) {
		return 0;
	}
	int b = lg[r - l + 1];
	return __gcd(f[l][b], f[r - (1 << b) + 1][b]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i][0] = abs(a[i] - a[i - 1]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		g[i][0] = abs(b[i] - b[i - 1]);
	}
	for (int j = 1; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 0; i < m; i++) {
		int h1, h2, w1, w2;
		scanf("%d%d%d%d", &h1, &h2, &w1, &w2);
		int z = a[h1] + b[w1];
		z = __gcd(z, query(f, h1 + 1, h2));
		z = __gcd(z, query(g, w1 + 1, w2));
		printf("%d\n", z);
	}
	return 0;
}
