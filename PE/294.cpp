#include <bits/stdc++.h>
using namespace std;
int a[552][552];
int b[552][552];
int p = 1000000000;
void mul(int a[552][552], int b[552][552]) {
	int c[552][552] = {};
	for (int i = 0; i < 552; i++) {
		for (int k = 0; k < 552; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < 552; j++) {
				c[i][j] = (c[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, c, sizeof c);
}
int main() {
	a[0][0] = 1;
	for (int i = 0; i < 552; i++) {
		int x = i % 23;
		int y = i / 23;
		for (int j = 0; j < 10; j++) {
			int xx = (10 * x + j) % 23;
			int yy = (y + j);
			if (yy > 23) {
				continue;
			}
			b[i][yy * 23 + xx]++;
		}
	}
	long long n = 3138428376721LL;
//	long long n = 42;
	while (n > 0) {
		printf("%lld\n", n);
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
		n /= 2;
	}
	printf("%d\n", a[0][23 * 23 + 0]);
	return 0;
}