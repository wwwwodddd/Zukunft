#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200020];
long long c[200020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
long long query(int x) {
	long long re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		change(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int o, x, y;
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1) {
			change(x, y - a[x]);
			a[x] = y;
		} else {
			printf("%lld\n", query(y) - query(x - 1));
		}
	}
	return 0;
}