#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y, z, f[420][420];
int main() {
	scanf("%d%d%d", &l, &m, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		for (int j = l; j >= x; j--) {
			for (int k = m; k >= y; k--) {
				f[j][k] = max(f[j][k], f[j - x][k - y] + z);
			}
		}
	}
	printf("%d\n", f[l][m]);
	return 0;
}