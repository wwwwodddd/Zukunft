#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[120][120];
int d[120][120];
int main() {
	cin >> n >> m;
	memset(a, 0x1f, sizeof a);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = min(a[x][y], z);
		a[y][x] = min(a[y][x], z);
	}
	int ans = 0x1f1f1f1f;
	memcpy(d, a, sizeof d);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = 1; j < i; j++) {
				ans = min(ans, a[i][k] + a[k][j] + d[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	if (ans == 0x1f1f1f1f) {
		printf("No solution.\n");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}