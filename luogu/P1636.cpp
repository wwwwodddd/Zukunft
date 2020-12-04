#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int d[1020];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] & 1) {
			z++;
		}
	}
	if (z == 0) {
		z = 2;
	}
	printf("%d\n", z / 2);
	return 0;
}