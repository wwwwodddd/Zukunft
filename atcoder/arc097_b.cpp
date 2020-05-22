#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int a[100020];
int f[100020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		f[F(x)] = F(y);
	}
	for (int i = 1; i <= n; i++) {
		if (F(i) == F(a[i])) {
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}