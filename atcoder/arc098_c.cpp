#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[2020];
bool ok(int M) {
	for (int i = 0; i < n; i++) {
		int z = 0, c = 0;
		for (int j = 0, k; j < n; j = k + 1) {
			for (k = j; k < n; k++) {
				if (a[k] < a[i]) {
					break;
				}
				if (a[k] <= a[i] + M) {
					c++;
				}
			}
			if (k - j >= m) {
				z += min(k - j - m + 1, c);
			}
			c = 0;
		}
		if (z >= q) {
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int L = -1, R = 1e9;
	while (L < R - 1) {
		int M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%d\n", R);
	return 0;
}