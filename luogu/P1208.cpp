#include <bits/stdc++.h>
using namespace std;
long long n, a[1020], z;
int m, x, y;
int main() {
	scanf("%lld%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		a[x] += y;
	}
	for (int i = 0; i <= 1000; i++) {
		int t = min(n, a[i]);
		z += t * i;
		n -= t;
	}
	printf("%lld\n", z);
	return 0;
}