#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, m, x, y;
int f[2020];
int a[1020][1020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof a);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &x, &y);
			a[x][y] = 1;
			a[y][x] = 1;
		}
		for (int i = 0; i <= 2 * n; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 0 && i != j) {
					U(i, j + n);
					U(i + n, j);
				}
			}
		}
		bool wocaonima = false;
		for (int i = 1; i <= n; i++) {
			if (F(i) == F(i + n)) {
				wocaonima = true;
			}
		}
		if (wocaonima) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
}