#include <bits/stdc++.h>
using namespace std;
int a, m;
int d[1000001][11];
int main() {
	scanf("%d%d", &a, &m);
	for (int i = 0; i < m; i++) {
		d[i][0] = 1;
		for (int j = 1; j < 11; j++) {
			d[i][j] = (long long)d[i][j - 1] * i % m;
		}
	}
	a %= m;
	int ans = 1;
	char c;
	while (scanf(" %c", &c) != EOF) {
		ans = (long long)d[ans][10] * d[a][c - '0'] % m;
	}
	printf("%d\n", ans);
	return 0;
}