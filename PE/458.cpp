#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[150][150];
int b[150][150];
int m = 7;
int p = 1000000000;
void mul(int a[150][150], int b[150][150], int c[150][150]) {
	int re[150][150] = {};
	for (int i = 0; i < 1 << m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			for (int k = 0; k < 1 << m; k++) {
				re[i][j] = (re[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(c, re, sizeof re);
}

int main() {
	a[0][0] = 1;
	for (int i = 0; i < (1 << m); i++) {
		b[i][(i >> 1) | (1 << (m - 1))] = m - __builtin_popcount(i);
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				int t = i ^ (1 << j);
				b[i][(t >> 1) | (1 << (m - 1))]++;
			}
		}
	}

	for (int i = 0; i < 1 << m; i++) {
		b[i][127] = b[127][i] = 0;
	}

//	for (int i = 0; i < 1 << m; i++) {
//		if (b[i][126]) {
//			printf("%d %d %d\n", i, 126, b[i][126]);
//		}
//		for (int j = 0; j < 1 << m; j++) {
//			if ()
//		}
//	}
	long long n = 1000000000000LL;
//	long long n = 8;
	while (n > 0) {
		if (n & 1) {
			mul(a, b, a);
		}
		mul(b, b, b);
		n >>= 1;
	}

/*
	for (int i = 0; i < 1 << m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			printf("%d%c", a[i][j], j == (1 << m) - 1 ? '\n' : ' ');
		}
	}
	printf("\n");
	mul(a, b, a);
//	mul(a, b, a);mul(a, b, a);
	for (int i = 0; i < 1 << m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			printf("%d%c", a[i][j], j == (1 << m) - 1 ? '\n' : ' ');
		}
	}

*/
	int ans = 0;
	for (int i = 0; i < (1 << m); i++) {
		if (a[0][i] > 0) {
			printf("%d %d\n", i, a[0][i]);
		}
		ans = (ans + a[0][i]) % p;
	}
	printf("%d\n", ans);
	return 0;
}