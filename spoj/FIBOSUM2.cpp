#include <stdio.h>
#include <iostream>
using namespace std;
int p = 1000000007;
long long a[3][3];
long long b[3][3];
long long d[3][3];
long long e[3][3];
void mul(long long a[3][3], long long b[3][3]) {
	long long w[3][3] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				w[i][j] += a[i][k] * b[k][j];
				w[i][j] %= p;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = w[i][j];
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d%d%lld", &c, &k, &n);
		k += c;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		memset(d, 0, sizeof d);
		a[0][0] = 0;
		a[0][1] = 1;
		a[0][2] = 0;
		b[1][0] = 1;
		b[0][1] = 1;
		b[1][1] = 1;
		b[2][2] = 1;
		memcpy(d, b, sizeof b);
		for (; k; k >>= 1) {
			if (k & 1) {
				mul(a, b);
			}
			mul(b, b);
		}
		for (; c; c >>= 1) {
			if (c & 1) {
				mul(e, d);
			}
			mul(d, d);
		}
		e[1][2] = 1;
		for (; n; n >>= 1) {
			if (n & 1) {
				mul(a, e);
			}
			mul(e, e);
		}
		printf("%d\n", (int)a[0][2]);
	}
	return 0;
}