#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[100020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] ^= y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re ^= c[i];
	}
	return re;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int o, x, y;
		scanf("%d", &o);
		if (o == 1) {
			scanf("%d%d", &x, &y);
			change(x, 1);
			change(y + 1, 1);
		} else {
			scanf("%d", &x);
			printf("%d\n", query(x));
		}
	}
	return 0;
}