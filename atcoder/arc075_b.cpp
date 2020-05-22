#include <bits/stdc++.h>
using namespace std;
int n, a, b, h[100020];
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	long long L = 0, R = 1e9;
	while (L < R - 1) {
		long long M = (L + R) / 2, c = 0;
		for (int i = 0; i < n; i++) {
			c += max(h[i] - M * b + a - b - 1, 0LL) / (a - b);
		}
		if (M < c) {
			L = M;
		} else {
			R = M;
		}
	}
	printf("%lld\n", R);
	return 0;
}