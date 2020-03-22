#include <bits/stdc++.h>
using namespace std;
int c[2020][2020];
int s[2020][2020];
int t, k, n, m;
int main() {
	scanf("%d%d", &t, &k);
	for (int i = 0; i < 2010; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % k;
			s[i][j] = c[i][j] == 0;
		}
	}
	for (int i = 1; i < 2010; i++) {
		for (int j = 1; j < 2010; j++) {
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
/*
	for (int i = 1; i < 2010; i++) {
		for (int j = 1; j < 2010; j++) {
			s[i][j] += s[i][j - 1];
		}
	}
	for (int i = 1; i < 2010; i++) {
		for (int j = 1; j < 2010; j++) {
			s[i][j] += s[i - 1][j];
		}
	}
*/
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		printf("%d\n", s[n][m]);
	}
	return 0;
}