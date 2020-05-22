#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1000000007;
long long z = 1;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		z = z * i % p;
	}
	for (int i = 1; i <= m; i++) {
		z = z * i % p;
	}
	if (abs(n - m) > 1) {
		z = 0;
	} else if (n == m) {
		z = z * 2 % p;
	}
	printf("%lld\n", z);
	return 0;
}