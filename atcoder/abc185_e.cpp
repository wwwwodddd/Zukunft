#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1020];
int b[1020];
int f[1020][1020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				f[i][j] = i + j;
			} else if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1];
			} else {
				f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
			}
		}
	}
	printf("%d\n", f[n][m]);
	return 0;
}