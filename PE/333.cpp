#include <iostream>
#include <cstdio>
using namespace std;
int v[1000020];
int f[1000020];
int n = 1000000;
long long a[30][30];
void dfs(int x, int y, int s, bool upd) {
//	printf("%d %d\n", x, y);
	if (upd) {
		f[s]++;
	}
	if (a[x][0] > n) {
		return;
	}
	for (int i = y; i >= 0; i--) {
		if (s + a[x][i] <= n) {
			dfs(x + 1, i - 1, s + a[x][i], true);
		}
	}
	dfs(x + 1, y, s, false);
}
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] != 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	a[0][0] = 1;
	for (int i = 1; i < 22; i++) {
		a[0][i] = a[0][i - 1] * 2;
	}
	for (int i = 1; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			a[i][j] = a[i - 1][j] * 3;
		}
	}

	dfs(0, 21, 0, true);
	long long sum = 0;
	for (int i = 2; i < n; i++) {
		if (v[i] == i && f[i] == 1) {
//			printf("%d\n", i);
			sum += i;
		}
	}
	printf("%lld\n", sum);
	return 0;
}