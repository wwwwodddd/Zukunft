#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1020][1020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x2++;
		y2++;
		a[x1][y1]++;
		a[x1][y2]--;
		a[x2][y1]--;
		a[x2][y2]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d%c", a[i][j], j == n ? '\n' : ' ');
		}
	}
	return 0;
}