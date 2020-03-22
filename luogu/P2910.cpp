#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int a[10020];
int d[120][120];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i < m; i++) {
		ans += d[a[i - 1]][a[i]];
	}
	cout << ans << endl;
}