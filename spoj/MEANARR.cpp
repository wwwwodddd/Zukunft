#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[500020], k;
long long b[500020];
int c[500020];
void change(int x, int y) {
	for (int i = x; i <= m; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d%lld", &n, &k);
	m = n + 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1] - k;
		b[i] = a[i];
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	long long z = 0;
	for (int i = 0; i <= n; i++) {
		a[i] = lower_bound(b, b + m, a[i]) - b + 1;
		z += query(a[i]);
		change(a[i], 1);
	}
	printf("%lld\n", z);
	return 0;
}