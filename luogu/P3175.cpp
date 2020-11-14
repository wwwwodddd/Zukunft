#include <bits/stdc++.h>
using namespace std;
int n;
double a[1 << 20], z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; i++) {
		scanf("%lf", &a[i]);
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 1 << n; i++) {
			if (i >> j & 1) {
				a[i] += a[i ^ (1 << j)];
			}
		}
	}
	for (int i = 0; i < (1 << n) - 1; i++) {
		if (a[i] > 1 - 1e-9) {
			printf("INF\n");
			return 0;
		}
		if ((n - __builtin_popcount(i)) & 1) {
			z += 1 / (1 - a[i]);
		} else {
			z -= 1 / (1 - a[i]);
		}
	}
	printf("%.10F\n", z);
	return 0;
}