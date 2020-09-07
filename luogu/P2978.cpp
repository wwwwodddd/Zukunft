#include <bits/stdc++.h>
using namespace std;
int f[1020];
int n, m, q, x, y;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		f[F(x)] = F(y);
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		if (F(x) == F(y)) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}