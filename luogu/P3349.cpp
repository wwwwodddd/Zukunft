#include <bits/stdc++.h>
using namespace std;
int b[17][17], v[17], x, y, n, m;
vector<int> a[17];
long long f[17][17], ans;
void dfs(int x, int y) {
	for (int j = 0; j < n; j++) {
		f[x][j] = v[j];
	}
	for (int ii = 0; ii < a[x].size(); ii++) {
		int i = a[x][ii];
		if (i == y) {
			continue;
		}
		dfs(i, x);
		for (int j = 0; j < n; j++) {
			long long s = 0;
			for (int k = 0; k < n; k++) {
				if (b[j][k]) {
					s += f[i][k];
				}
			}
			f[x][j] *= s;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		b[x][y] = b[y][x] = 1;
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i < 1 << n; i++) {
		for (int j = 0; j < n; j++) {
			v[j] = i >> j & 1;
		}
		dfs(0, -1);
		int t = n - __builtin_popcount(i);
		t = 1 - t % 2 * 2;
		for (int i = 0; i < n; i++) {
			ans += t * f[0][i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}