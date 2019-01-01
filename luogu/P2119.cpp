#include <bits/stdc++.h>
using namespace std;
int a[40020];
int b[40020];
int c[40020];
int d[40020];
int x[40020];
int w[40020];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x[i]);
		w[x[i]]++;
	}
	for (int i = 1; 9 * i <= n; i++) {
		int ab = 0, cd = 0;
		for (int j = 8 * i; j + i <= n; j++) {
			c[j] += w[j + i] * ab;
			d[j + i] += w[j] * ab;
			ab += w[j - 8 * i] * w[j - 6 * i];
		}

		for (int j = n - 7 * i; j >= 2 * i; j--) {
			b[j] += w[j - 2 * i] * cd;
			a[j - 2 * i] += w[j] * cd;
			cd += w[j + 6 * i] * w[j + 7 * i];
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d %d %d %d\n", a[x[i]], b[x[i]], c[x[i]], d[x[i]]);
	}
	return 0;
}