#include <bits/stdc++.h>
using namespace std;
int n, k;
long long w[100020], d[100020];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &w[i], &d[i]);
	}
	long long L = 0, R = 2e18;
	while (L < R - 1) {
		long long M = (L + R) / 2, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (M >= w[i]) {
				cnt += (M - w[i]) / d[i] + 1;
			}
			if (cnt >= k) {
				break;
			}
			assert(cnt >= 0);
		}
		if (cnt >= k) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%lld\n", R);
	return 0;
}