#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[100020][18];
int lg[100020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i][0]);
	}
	for (int j = 1; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) {
		lg[i] = lg[i / 2] + 1;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		int b = lg[r - l + 1];
		printf("%d ", min(f[l][b], f[r - (1 << b) + 1][b]));
	}
	return 0;
}