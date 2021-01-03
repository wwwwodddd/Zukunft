#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long n;
int m;
long long a[101][101];
long long b[101][101];
void mul(long long a[101][101], long long b[101][101]) {
	long long w[101][101] = {};
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < m; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < m; j++) {
				w[i][j] |= a[i][k] & b[k][j];
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[0][i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i][m - 1];
		if (i > 0)
		{
			b[i][i - 1] = -1;
		}
	}
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	cout << a[0][0] << endl;
	return 0;
}