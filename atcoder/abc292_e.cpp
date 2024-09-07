#include <bits/stdc++.h>
using namespace std;
bitset<2000>d[2000];
char s[2020];
int n, m, x, y, z;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		d[--x][--y] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (d[i][k]) {
				d[i] |= d[k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		d[i][i] = 0;
		z += d[i].count();
	}
	printf("%d\n", z - m);
	return 0;
}