#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y, z;
int d[320][320];
int main() {
	cin >> n >> m >> l;
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		d[x][y] = z;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}
	for (int i = 0; i < l; i++) {
		cin >> x >> y;
		cout << (d[x][y] == 0x3f3f3f3f ? -1 : d[x][y]) << endl;
	}
	return 0;
}