#include <bits/stdc++.h>
using namespace std;
int n;
long long z = -1e18, y = 1e18, x;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);
		z = max(z, x - y);
		y = min(y, x);
	}
	printf("%lld\n", z);
	return 0;
}