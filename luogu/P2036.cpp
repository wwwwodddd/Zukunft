#include <bits/stdc++.h>
using namespace std;
int n, a[10], b[10], z = 1e9;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i < 1 << n; i++) {
		int A = 1, B = 0;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				A *= a[j];
				B += b[j];
			}
		}
		z = min(z, abs(A - B));
	}
	printf("%d\n", z);
	return 0;
}