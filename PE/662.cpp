#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int f[10001][10001];
int v[20002];
int dx[1000];
int dy[1000];
int dc;
bool ok(int x, int y) {
	int rt = (int)(sqrt(x * x + y * y) + 0.5);
	return rt * rt == x * x + y * y && v[rt];
}
int main() {
	int n = 10000;
	int m = 10000;
	{
		int x = 1, y = 1;
		while (x <= n + m) {
			v[x] = true;
			int z = (x + y);
			x = y;
			y = z;
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (ok(i, j)) {
				dx[dc] = i;
				dy[dc] = j;
				dc++;
			}
		}
	}
	printf("%d\n", dc);
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k < dc; k++) {
				if (i + dx[k] <= n && j + dy[k] <= m) {
					f[i + dx[k]][j + dy[k]] = (f[i + dx[k]][j + dy[k]] + f[i][j]) % mod;
				}
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}
