#include <bits/stdc++.h>
using namespace std;
int n, l, q;
int x[100020];
int f[100020][17];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	scanf("%d%d", &l, &q);
	for (int i = 0; i < n; i++) {
		f[i][0] = upper_bound(x, x + n, x[i] + l) - x - 1;
	}
	f[0][n] = n;
	for (int j = 1; j < 17; j++) {
		for (int i = 0; i <= n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int x, y, z = 0;
		scanf("%d%d", &x, &y);
		if (x > y) {
			swap(x, y);
		}
		x--;
		y--;
		for (int i = 16; i >= 0; i--) {
			if (f[x][i] < y) {
				z += 1 << i;
				x = f[x][i];
			}
		}
		printf("%d\n", z + 1);
	}
	return 0;
}