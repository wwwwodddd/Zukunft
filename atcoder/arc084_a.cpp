#include <bits/stdc++.h>
using namespace std;
int n, a[100020], b[100020], c[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int first = lower_bound(a, a + n, b[i]) - a;
		int third = n - (upper_bound(c, c + n, b[i]) - c);
		ans += (long long)first * third;
	}
	printf("%lld\n", ans);
	return 0;
}