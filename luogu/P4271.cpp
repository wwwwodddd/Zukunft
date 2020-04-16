#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> a[500020];
int b[500020][3];
int f[500020][20];
int d[500020];
int lca(int x, int y) {
	if (d[x] < d[y]) {
		swap(x, y);
	}
	int dd = d[x] - d[y];
	for (int i = 0; i < 20; i++) {
		if (dd >> i & 1) {
			x = f[x][i];
		}
	}
	if (x == y) {
		return x;
	}
	for (int i = 20 - 1; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int dist(int x, int y) {
	return d[x] + d[y] - 2 * d[lca(x, y)];
}
int main() {
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char o;
		int x;
		scanf(" %c%d", &o, &x);
		if (o == 'B') {
			if (x == -1) {
				int z = ++n;
				f[z][0] = z;
				for (int i = 1; i < 20; i++) {
					f[z][i] = f[f[z][i-1]][i-1];
				}
				b[z][0] = b[z][1] = z;
			} else {
				int z = ++n;
				f[z][0] = x;
				d[z] = d[x] + 1;
				for (int i = 1; i < 20; i++) {
					f[z][i] = f[f[z][i-1]][i-1];
				}
				int y = f[x][19];
				int d0 = dist(z, b[y][1]);
				if (b[y][2] < d0) {
					b[y][2] = d0;
					b[y][0] = z;
				}
				int d1 = dist(b[y][0], z);
				if (b[y][2] < d1) {
					b[y][2] = d1;
					b[y][1] = z;
				}
			}
		} else {
			int y = f[x][19];
			printf("%d\n", max(dist(x, b[y][0]), dist(x, b[y][1])));
		}
	}
	return 0;
}