#include <bits/stdc++.h>
using namespace std;
char c[60][60];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '#') {
				printf("%c", c[i][j]);
			} else {
				int cnt = 0;
				for (int k = max(i - 1, 0); k <= min(i + 1, n - 1); k++) {
					for (int l = max(j - 1, 0); l <= min(j + 1, m - 1); l++) {
						if (c[k][l] == '#') {
							cnt++;
						}
					}
				}
				printf("%d", cnt);
			}
		}
		printf("\n");
	}
	return 0;
}