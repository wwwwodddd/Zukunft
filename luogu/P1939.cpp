#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
void mul(int a[3][3], int b[3][3]) {
	int w[3][3] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int F(long long n) {
	int a[3][3] = {};
	int b[3][3] = {};
	a[0][1] = a[0][2] = 1;
	b[1][0] = b[2][1] = b[0][2] = b[2][2] = 1;
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