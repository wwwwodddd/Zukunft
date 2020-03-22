#include <bits/stdc++.h>
using namespace std;
long long n;
int p, m, r;
int a[50][50];
int b[50][50];
void mul(int a[50][50], int b[50][50]) {
	int w[50][50] = {};
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
	cin >> n >> p >> m >> r;
	n *= m;
	a[0][0] = 1;
	for (int i = 0; i < m; i++)
	{
		b[i][i]++;
		b[i][(i+1) % m]++;
	}
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	cout << a[0][r] << endl;
	return 0;
}