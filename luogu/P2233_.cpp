#include <bits/stdc++.h>
using namespace std;
int p = 1000;
void mul(int a[4][4], int b[4][4]) {
	int w[4][4] = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				w[i][j] = (w[i][j] + a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int F(long long n) {
	int a[4][4] = {};
	int b[4][4] = {};
	a[0][3] = 1;
	b[0][1] = b[1][0] = b[1][2] = b[2][1] = b[3][2] = 1;
	b[2][3] = 2;
	for (n--; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	return a[0][0];
}
int main() {
	long long n;
	cin >> n;
	cout << F(n) * 2 % p << endl;
	return 0;	
}
