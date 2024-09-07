#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int f[100020][18];
int lg[100020];
int main() {
	scanf("%d", &n);
	for (int j = 0; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = ++m; 
		}
	}
	printf("%d\n", m);
	for (int j = 0; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			printf("%d %d\n", i, i + (1 << j) - 1);
		}
	}
	fflush(stdout);
	lg[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int b = lg[r - l + 1];
		printf("%d %d\n", f[l][b], f[r - (1 << b) + 1][b]);
		fflush(stdout);
	}
	return 0;
}
