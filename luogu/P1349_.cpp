#include <bits/stdc++.h>
using namespace std;
int n, p;
void mul(int a[2][2], int b[2][2]) {
	int w[2][2] = {};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	int a[2][2] = {};
	int b[2][2] = {};
	cin >> b[0][0] >> b[1][0] >> a[0][1] >> a[0][0] >> n >> p;
	b[0][1] = 1;
	n--;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	printf("%d\n", a[0][1] % p);
	return 0;
}