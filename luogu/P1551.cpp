#include <bits/stdc++.h>
using namespace std;
int f[5020];
int n, m, q, x, y;
int F(int x) {
	if (f[x] == x) {
		return x;
	}
	f[x] = F(f[x]);
	return f[x];
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
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}