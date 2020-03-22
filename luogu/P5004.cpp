#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long n;
int m;
int a[20][20];
int b[20][20];
void mul(int a[20][20], int b[20][20]) {
	int w[20][20] = {};
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < m; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < m; j++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		a[0][i] = i + 1;
		b[i+1][i] = 1;
	}
	b[0][m] = b[m][m] = 1;
	a[0][m] = m + 1;
	m++;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	printf("%d\n", a[0][0]);
	return 0;
}