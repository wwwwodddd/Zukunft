#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
void mul(int a[5][5], int b[5][5]) {
	int w[5][5] = {};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int F(long long n) {
	int a[5][5] = {};
	int b[5][5] = {};
	a[0][0] = 0;
	a[0][1] = 1;
	a[0][2] = 3;
	a[0][3] = 6;
	a[0][4] = 11;
	b[1][0] = b[2][1] = b[3][2] = b[4][3] = 1;
	b[0][4] = p - 1;
	b[1][4] = 1;
	b[2][4] = p - 1;
	b[4][4] = 2;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	return a[0][0];
}
int main() {
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		long long n;
		cin >> n;
		cout << F(n) << endl;
	}
	return 0;
}