#include <bits/stdc++.h>
using namespace std;
int a[10020], b[10020], c[10020], d[10020], n, x, y, z = -2;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
	}
	scanf("%d%d", &x, &y);
	for (int i = 0; i < n; i++) {
		if (a[i] <= x && x <= a[i] + c[i] && b[i] <= y && y <= b[i] + d[i]) {
			z = i;
		}
	}
	printf("%d\n", z + 1);
	return 0;
}