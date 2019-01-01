#include <bits/stdc++.h>
using namespace std;
int t, n, h, r;
int f[1020];
int x[1020];
int y[1020];
int z[1020];
typedef unsigned long long ull;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
ull D(int i, int j) {
	ull dx = (ull)(x[i] - x[j]) * (x[i] - x[j]);
	ull dy = (ull)(y[i] - y[j]) * (y[i] - y[j]);
	ull dz = (ull)(z[i] - z[j]) * (z[i] - z[j]);
	return dx + dy + dz;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d%d", &n, &h, &r);
		for (int i = 0; i < n + 2; i++) {
			f[i] = i;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			if (z[i] - r  <= 0) {
				U(i, n);
			}
			if (z[i] + r >= h) {
				U(i, n + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (D(i, j) <= 4LL * r * r) {
					U(i, j);
				}
			}
		}
		printf("%s\n", F(n) == F(n + 1) ? "Yes" : "No");
	}
	return 0;
}