#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[200020];
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y) {
	f[F(x)] = F(y);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i <= 2 * n; i++) {
		f[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		char o;
		cin >> o >> x >> y;
		if (o == 'S') {
			U(x, y);
			U(x + n, y + n);
		} else {
			U(x + n, y);
			U(x, y + n);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (F(i) == F(i + n)) {
			printf("0\n");
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (F(i) == i) {
			cnt++;
		}
	}
	cnt /= 2;
	printf("1");
	for (int i = 0; i < cnt; i++) {
		printf("0");
	}
	printf("\n");
	return 0;
}