#include <stdio.h>
#include <iostream>
using namespace std;
int f[21][(1 << 19) + 1], t, n, s, l, p = 1000000007, z;
void add(int &x, int y) {
	x += y;
	if (x >= p) {
		x -= p;
	}
}
int F(int x) {
	x &= (1 << s) - 1;
	if (x >= 1 << (s - 1)) {
		x = 1 << (s - 1);
	}
	return x;
}
int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d%d%d", &n, &s, &l);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 1 << (s - 1); j++) {
				f[i][j] = 0;
			}
		}
		f[0][0] = 1;
		z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 1 << (s - 1); j++)  {
				if (f[i][j]) {
					for (int k = 0; k <= min(s, l); k++) {
						add(f[i + 1][F((j | j << k | (k ? 1 << (k - 1) : 0)))], f[i][j]);
					}
					if (l > s) {
						add(f[i + 1][j], (long long)f[i][j] * (l - s) % p);
					}
				}
			}
		}
		printf("%d\n", f[n][1 << (s - 1)]);
	}
	return 0;
}
