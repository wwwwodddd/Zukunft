#include <bits/stdc++.h>
using namespace std;
long long f[120][4020], z;
int n, k, p = 1000000007;
int main() {
	cin >> n >> k;
	z = k * (k + 1) / 2 * n;
	for (int i = 1; i < n; i++) {
		z = z * (k + 1) % p;
	}
	f[n][0] = 1;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < 4010; j++) {
			if (f[i][j] == 0) {
				continue;
			}
			for (int l = 0; l <= k; l++) {
				if (l <= i) {
					f[i - 1][j + (j + l) / i] = (f[i - 1][j + (j + l) / i] + f[i][j]) % p;
				} else {
					f[i - 1][j] = (f[i - 1][j] + f[i][j]) % p;
				}
			}
		}
	}
	for (int i = 0; i < 4010; i++) {
		z = (z - i * f[0][i]) % p;
	}
	cout << (z + p) % p << endl;
	return 0;
}