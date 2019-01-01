#include <bits/stdc++.h>
using namespace std;
int n;
int a[220], s[220];
int f[220][220];
int g[220][220];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i + l - 1 <= 2 * n; i++) {
			int j = i + l - 1;
			f[i][j] = 1e9;
			g[i][j] = 0;
			for (int k = i; k < j; k++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}
	int ans1 = 1e9;
	int ans2 = 0;
	for (int i = 1; i <= n; i++) {
		ans1 = min(ans1, f[i][i + n - 1]);
		ans2 = max(ans2, g[i][i + n - 1]);
	}
	cout << ans1 << endl << ans2 << endl;
}