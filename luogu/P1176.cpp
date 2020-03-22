#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[1020][1020];
int main() {
	cin >> n >> m;
	f[0][1] = 1;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		f[x][y] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[i][j] == -1) {
				f[i][j] = 0;
			} else {
				f[i][j] = (f[i-1][j] + f[i][j-1]) % 100003;
			}
		}
	}
	cout << f[n][n] << endl;
	return 0;
}