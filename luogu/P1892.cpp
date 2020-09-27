#include <bits/stdc++.h>
using namespace std;
int f[1020];
int e[1020];
int n, m, x, y, z;
char o;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	x = F(x);
	y = F(y);
	if (x != y) {
		z--;
		f[x] = y;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	z = n;
	for (int i = 0; i < m; i++) {
		cin >> o >> x >> y;
		if (o == 'F') {
			U(x, y);
		} else {
			if (e[x]) {
				U(e[x], y);
			} else {
				e[x] = y;
			}
			if (e[y]) {
				U(e[y], x);
			} else {
				e[y] = x;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}