#include <bits/stdc++.h>
using namespace std;
long long f[420][420];
long long a[420];
int n, m;
int main() {
	cin >> n >> m;
	m++;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			long long sm = 0;
			long long mx = 0;
			for (int k = i - 1; k >= 0; k--) {
				sm += a[k];
				mx = max(mx, a[k]);
				f[i][j] = min(f[i][j], f[k][j - 1] + (mx * (i - k) - sm));
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}