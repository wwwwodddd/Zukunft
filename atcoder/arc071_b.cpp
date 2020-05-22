#include <bits/stdc++.h>
using namespace std;
int n, m, p = 1000000007;
long long a, b, x;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		a += x * (2 * i + 1 - n);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld", &x);
		b += x * (2 * i + 1 - m);
	}
	a %= p;
	b %= p;
	printf("%lld\n", a * b % p);
	return 0;
}