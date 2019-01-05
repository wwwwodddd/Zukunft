#include <bits/stdc++.h>
using namespace std;
int n, m, k, x, y, c;
int f[400020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < 2 * n + 2 * m; i++) {
		f[i] = i;
	}
	for (int i = 0; i < k; i++) {
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;
		if (x % 2 == 1 && y % 2 == 1) {
			c ^= 1;
		}
		if (c == 0) {
			U(x, y + n);
			U(x + n + m, y + n + n + m);
		} else {
			U(x, y + n + n + m);
			U(x + n + m, y + n);
		}
	}
	for (int i = 0; i < n + m; i++) {
		if (F(i) == F(i + n + m)) {
			printf("0\n");
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2 * n + 2 * m; i++) {
		if (F(i) == i) {
			cnt++;
		}
	}
	int ans = 1;
	for (int i = 0; i < cnt / 2 - 1; i++) {
		ans = ans * 2 % 1000000000;
	}
	printf("%d\n", ans);
	return 0;
}