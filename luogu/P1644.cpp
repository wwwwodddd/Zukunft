#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[21][21];
int dx[] = {-1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2};
int main() {
	cin >> m >> n;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				if (i + dx[k] >= 0 && j + dy[k] >= 0) {
					f[i][j] += f[i + dx[k]][j + dy[k]];
				}
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}