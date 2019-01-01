#include <bits/stdc++.h>
using namespace std;
int n, a[60], p = 1000000007;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long z = 1;
	for (int i = 0; i < n; i++) {
		z = z * (a[i] - i) % p;
	}
	printf("%lld\n", z);
	return 0;
}