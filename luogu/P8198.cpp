#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100020];
bool ok(long long M) {
	long long s = M, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s + a[i] > M) {
			s = 0;
			cnt++;
		}
		s += a[i];
		if (s > M) {
			return false;
		}
	}
	return cnt <= m;
}
int main() {
	scanf("%d%d", &n, &m);
	long long L = 0, R = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		a[i] *= a[i];
		R += a[i];
	}
	while (L < R - 1) {
		long long M = (L + R) / 2;
		if (ok(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	printf("%lld\n", R);
	return 0;
}
