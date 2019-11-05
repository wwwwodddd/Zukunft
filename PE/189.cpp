#include <bits/stdc++.h>
using namespace std;
long long f[20][10000];
int pw[20];
int ok(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		if (x % 3 == y % 3) {
			return false;
		}
		x /= 3;
		y /= 3;
	}
	return true;
}
int main() {
	for (int i = 0; i < 3; i++) {
		f[0][i] = 1;
	}
	int n = 8;
	pw[0] = 1;
	for (int i = 1; i < n + 2; i++) {
		pw[i] = pw[i - 1] * 3;
	}
	for (int i = 1; i < 2 * n - 1; i++) {
		if (i & 1) {
			for (int j = 0; j < pw[i / 2 + 1]; j++) {
				for (int k = 0; k < pw[i / 2 + 1]; k++) {
					if (ok(j, k, (i + 1) / 2)) {
						f[i][j] += f[i - 1][k];
					}
				}
			}
		} else {
			for (int j = 0; j < pw[i / 2 + 1]; j++) {
				for (int k = 0; k < pw[i / 2]; k++) {
					if (ok(j, k, i / 2) && ok(j / 3, k, i / 2)) {
						f[i][j] += f[i - 1][k];
					}
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < pw[n]; i++) {
		ans += f[2 * n - 2][i];
	}
	printf("%lld\n", ans);
	return 0;
}