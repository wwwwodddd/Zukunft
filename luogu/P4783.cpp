#include <bits/stdc++.h>
using namespace std;
int n, a[401][801];
const int p = 1000000007;
int pw(int x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		a[i][n + i] = 1;
	}
	for (int i = 0; i < n; i++) {
		int t = i;
		for (int j = i; j < n; j++) {
			if (a[j][i] > 0) {
				t = j;
			}
		}
		swap(a[t], a[i]);
		int u = pw(a[i][i], p - 2);
		if (u == 0) {
			printf("No Solution\n");
			return 0;
		}
		for (int j = 0; j < 2 * n; j++) {
			a[i][j] = (long long)a[i][j] * u % p;
		}
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			u = a[j][i];
			for (int k = 0; k < 2 * n; k++) {
				a[j][k] = (a[j][k] - (long long)u * a[i][k]) % p;
				if (a[j][k] < 0) {
					a[j][k] += p;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", a[i][j + n], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}