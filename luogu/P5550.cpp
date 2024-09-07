#include <bits/stdc++.h>
using namespace std;
int n, s, m;
long long k;
void mul(long long a[81][81], long long b[81][81]) {
	long long w[81][81] = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				w[i][j] = (w[i][j] + a[i][k] * b[k][j]);
			}
		}
	}
	memcpy(a, w, sizeof w);
}
long long a[81][81];
long long b[81][81];
long long c[81][81];
int main() {
	cin >> n >> s >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[1][i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i][i] = 1;
	}
	b[s][s] = b[m][m] = 0;
	b[s][m] = b[m][s] = 1;
	for (int i = 1; i < n; i++)
	{
		c[i + 1][i] = 1;
	}
	c[1][n] = 1;
	mul(b, c);
	for (; k > 0; k >>= 1) {
		if (k & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[1][i] << " ";
	}
	cout << endl;
	return 0;	
}
