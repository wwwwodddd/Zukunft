#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool d[120][120];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		d[x][y] = true;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {
					d[i][j] = true;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		bool can = true;
		for (int j = 1; j <= n; j++) {
			if (i != j && !d[i][j] && !d[j][i]) {
				can = false;
			}
		}
		if (can) {
			ans++;
		}
	}
	cout << ans << endl;
}