#include <bits/stdc++.h>
using namespace std;
int a[620][620], n, d1, d2, z;
void gao(int d) {
	int b = 0;
	while (d % 4 == 0) {
		d /= 4;
		b++;
	}
	if (d & 1) {
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if (((i >> b) + (j >> b)) & 1) {
					a[i][j] = 1;
				}
			}
		}
	} else {
		for (int i = 0; i < 2 * n; i++) {
			for (int j = 0; j < 2 * n; j++) {
				if ((i >> b) & 1) {
					a[i][j] = 1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &d1, &d2);
	gao(d1);
	gao(d2);
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (z < n * n && !a[i][j]) {
				printf("%d %d\n", i, j);
				z++;
			}
		}
	}
	return 0;
}