#include <bits/stdc++.h>
using namespace std;
int n, a[100020], b[100020];
long long z;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	sort(a, a + n + 1);
	sort(b, b + n + 1);
	for (int i = 0; i <= n; i++) {
		z += max(0, a[i] - b[n - i]);
	}
	printf("%lld\n", z * 2);
	return 0;
}