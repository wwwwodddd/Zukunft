#include <bits/stdc++.h>
using namespace std;
long long L, R;
int m, p;
int b[20];
int c[20];
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
int F(long long n) {
	int a[20][20] = {};
	int b[20][20] = {};
	b[0][0] = 1;
	for (int i = 1; i < m; i++) {
		a[0][i] = ::b[i];
		b[i][i-1] = 1;
		b[m-i][m-1] = ::c[i];
	}
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	return a[0][0];
}
int main() {
	cin >> m;
	m++;
	for (int i = 1; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < m; i++) {
		cin >> c[i];
	}
	cin >> L >> R >> p;
	cout << (F(R) - F(L-1) + p) % p << endl;
	return 0;
}