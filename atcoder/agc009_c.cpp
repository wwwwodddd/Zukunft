#include <bits/stdc++.h>
using namespace std;
int n, L, R, p = 1000000007;
long long a[100020], A, B;
int f[100020];
int s[100020];
int main() {
	scanf("%d%lld%lld", &n, &A, &B);
	if (A > B) {
		swap(A, B);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 2] < A) {
			printf("0\n");
			return 0;
		}
	}
	a[0] = a[1] - B;
	s[1] = f[0] = 1;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[R] >= B) {
			R++;
		}
		f[i] = (s[R] - s[L] + p) % p;
		s[i + 1] = (s[i] + f[i]) % p;
		if (i > 0 && a[i] - a[i - 1] < A) {
			L = i - 1;
			R = max(R, L);
		}
	}
	printf("%d\n", (s[n + 1] - s[L] + p) % p);
	return 0;
}