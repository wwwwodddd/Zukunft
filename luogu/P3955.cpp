#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int a[1020];
int t[10];
int main() {
	scanf("%d%d", &n, &q);
	for (int i = t[0] = 1; i < 10; i++) {
		t[i] = t[i - 1] * 10;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &x, &y);
		int z = 1e9;
		for (int j = 0; j < n; j++) {
			if (a[j] % t[x] == y) {
				z = min(z, a[j]);
			}
		}
		if (z == 1e9) {
			z = -1;
		}
		printf("%d\n", z);
	}
	return 0;
}