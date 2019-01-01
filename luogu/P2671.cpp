#include <bits/stdc++.h>
using namespace std;
int n, m, ans, p = 10007;
int a[100020];
int c[100020];
int f[100020][2];
int g[100020][2];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[c[i]][i & 1]++;
		g[c[i]][i & 1] = (g[c[i]][i & 1] + a[i]) % p;
	}
	for (int i = 1; i <= n; i++) {
		ans = (ans + i * ((f[c[i]][i & 1] - 2) * a[i] % p + g[c[i]][i & 1])) % p;
	}
	printf("%d\n", ans);
	return 0;
}