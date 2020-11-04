#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int a[620][620];
int s[620][620];
int z[620];
int S(int x1, int x2, int y1, int y2) {
	x1--;
	y1--;
	x1 = max(x1, 0);
	y1 = max(y1, 0);
	x2 = min(x2, n + m - 1);
	y2 = min(y2, n + m - 1);
	return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof a);
		memset(z, 0, sizeof z);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &x);
				a[i + j + 1][i + m - j] = x;
			}
		}
		for (int i = 1; i < n + m; i++) {
			for (int j = 1; j < n + m; j++) {
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
			}
		}
		for (int i = 1; i < n + m; i++) {
			for (int j = 1; j < n + m; j++) {
				if (a[i][j] == 0) {
					continue;
				}
				for (int d = 1; d < n + m - 1; d++) {
					z[d] += S(i - d, i + d, j - d, j + d) - S(i - d + 1, i + d - 1, j - d + 1, j + d - 1);
				}
			}
		}
		for (int i = 1; i < n + m - 1; i++) {
			printf("%d", z[i] / 2);
			if (i == n + m - 2) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	}
	return 0;
}