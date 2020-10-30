#include <bits/stdc++.h>
using namespace std;
int n;
int a[220], s[220];
int f[220][220];
int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			s[i] = s[i - 1] + a[i];
		}
		for (int l = 2; l <= n; l++) {
			for (int i = 1; i + l - 1 <= 2 * n; i++) {
				int j = i + l - 1;
				f[i][j] = 1e9;
				for (int k = i; k < j; k++) {
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + ((s[j] - s[k]) % 100) * ((s[k] - s[i - 1]) % 100));
				}
			}
		}
		cout << f[1][n] << endl;
	}
	return 0;
}