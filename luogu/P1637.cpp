#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500020];
int b[500020];
int c[500020];
int d[500020];
void change(int *c, int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int *c, int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	m = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(b, b + m, a[i]) - b + 1;
		ans += query(d, a[i] - 1);
		change(d, a[i], query(c, a[i] - 1));
		change(c, a[i], 1);
	}
	cout << ans << endl;
	return 0;
}