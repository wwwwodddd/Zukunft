#include <bits/stdc++.h>
using namespace std;
int n, m, a[30], z = 1e9;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 1 << n; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				s += a[j];
			}
		}
		if (s >= m) {
			z = min(z, s - m);
		}
	}
	printf("%d\n", z);
	return 0;
}