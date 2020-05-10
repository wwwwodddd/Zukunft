#include <bits/stdc++.h>
using namespace std;
int t, n, k;
long long b[300020];
long long a[300020];
bool ok(int l) {
	memset(a, 0, sizeof a);
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[c % l] * 2 <= b[i]) {
			a[c++ % l] = b[i];
		}
	}
	return c >= l * k;
}
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &b[i]);
		}
		sort(b, b + n);
		int L = 0, R = n + 1;
		while (L < R - 1) {
			int M = (L + R) >> 1;
			if (ok(M)) {
				L = M;
			} else {
				R = M;
			}
		}
		printf("Case #%d: %d\n", tt, L);
	}
	return 0;
}