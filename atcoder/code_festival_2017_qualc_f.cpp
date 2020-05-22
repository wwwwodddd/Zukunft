#include <bits/stdc++.h>
using namespace std;
int n, p = 1000000007;
int a[420], pa[420];
int b[420], pb[420];
long long f[420][420][420];
int t[420][420];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pa[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		pb[b[i]] = i;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (pa[k] <= i || pb[k] <= j) {
					t[i][j]++;
				}
			}
		}
	}
	f[0][0][0] = 1;
	for (int k = 1; k <= n / 3; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[k][i][j] = (f[k][i - 1][j] + f[k][i][j - 1] + p - f[k][i - 1][j - 1]) % p;
				if (i < pa[b[j]] && j < pb[a[i]]) {
					f[k][i][j] = (f[k][i][j] + f[k - 1][i - 1][j - 1] * (3 * k - t[i][j])) % p;
				}
			}
		}
	}
	long long z = f[n / 3][n][n];
	for (int i = 1; i <= n; i++) {
		if (i % 3) {
			z = z * i % p;
		}
	}
	cout << z << endl;
	return 0;
}