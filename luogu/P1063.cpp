#include <bits/stdc++.h>
using namespace std;
int n, a[220], ans;
int f[220][220];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l < 2 * n; i++) {
			int j = i + l;
			for (int k = i + 1; k < j; k++) {
				f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
				ans = max(ans, f[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}