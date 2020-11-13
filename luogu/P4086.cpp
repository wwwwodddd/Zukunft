#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100020];
long long s[100020];
long long f[100020];
long long x, y;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	f[n + 1] = 1e9;
	for (int i = n; i >= 1; i--) {
		s[i] = s[i + 1] + a[i];
		f[i] = min(f[i + 1], a[i]);
	}
	x = 0;
	y = 1;
	// x / y = 0;
	for (int i = 2; i < n; i++) {
		// x / y < (s[i] - f[i]) / (n - i + 1)
		if (x * (n - i) < (s[i] - f[i]) * y) {
			x = s[i] - f[i];
			y = n - i;
		}
	}
	for (int i = 2; i < n; i++) {
		if (x * (n - i) == (s[i] - f[i]) * y) {
			printf("%d\n", i - 1);
		}
	}
	return 0;
}