#include <bits/stdc++.h>
using namespace std;
int n, m;
double f[420][420];
int main() {
	cin >> n >> m;
	for (int j = 1; j <= m; j++) {
		f[0][j] = -0.5;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = 0.5 * (1 + f[i - 1][j - 1]) + 0.5 * f[i][j - 1];
		}
	}
	printf("%.12f\n", f[n][m]);
	return 0;
}