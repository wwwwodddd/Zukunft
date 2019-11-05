#include <stdio.h>
#include <string.h>
int f[2][151][151][151];
int twopower[300];
int threepower[300];
int fourpower[300];
int p = 1000000007, n;
int c[1000][1000];
int v[300];
int C(int x, int y) {
	int z = 1;
	for (int i = 0; i < y; i++) {
		z = (long long) z * (x - i) % p * v[i + 1] % p;
	}
	return z;
}
int pw(int x, int y) {
	int re = 1;
	for (int i = 0; i < y; i++) {
		re *= x;
	}
	return re;
}
void add(int i, int j, int k, int l, int dj, int dk, int dl, int dm) {
	int ni = i - 1;
	int nj = j - dj;
	int nk = k - dk + dj;
	int nl = l - dl + dk;
	int m = i * 3 - 4 * j - 3 * k - 2 * l;
	if (i >= 1 && j >= dj && k >= dk && l >= dl && i * 3 - 4 * j - 3 * k - 2 * l >= dm) {
		int mul = (long long) fourpower[dj] * threepower[dk] * twopower[dl] % p * c[j][dj] % p * c[k][dk] % p * c[l][dl] % p * c[m][dm] % p;
		f[ni & 1][nj][nk][nl] += (long long)f[i & 1][j][k][l] * mul % p;
		if (f[ni & 1][nj][nk][nl] >= p) {
			f[ni & 1][nj][nk][nl] -= p;
		}
	}
}
int main() {
	twopower[0] = 1;
	threepower[0] = 1;
	fourpower[0] = 1;
	for (int i = 1; i < 300; i++) {
		twopower[i] = twopower[i - 1] * 2 % p;
		threepower[i] = threepower[i - 1] * 3 % p;
		fourpower[i] = fourpower[i - 1] * 4 % p;
	}
	v[1] = 1;
	for (int i = 2; i < 300; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 0; i < 1000; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= p) {
				c[i][j] -= p;
			}
		}
	}
	printf("%d\n", c[0][1]);
	scanf("%d" ,&n);
	f[0][n * 3][0][0] = 1;
	for (int i = n * 4; i > 0; i--) {
		fprintf(stderr, "%d\n", i);
		memset(f[~i & 1], 0, sizeof f[0]);
		for (int j = 0; j <= n * 3; j++) {
			for (int k = 0; k <= n * 3; k++) {
				for (int l = 0; l <= n * 3; l++) {
					if (f[i & 1][j][k][l] == 0) {
						continue;
					}
					add(i, j, k, l, 3, 0, 0, 0);
					add(i, j, k, l, 2, 1, 0, 0);
					add(i, j, k, l, 2, 0, 1, 0);
					add(i, j, k, l, 2, 0, 0, 1);
					add(i, j, k, l, 1, 2, 0, 0);
					add(i, j, k, l, 1, 1, 1, 0);
					add(i, j, k, l, 1, 1, 0, 1);
					add(i, j, k, l, 1, 0, 2, 0);
					add(i, j, k, l, 1, 0, 1, 1);
					add(i, j, k, l, 1, 0, 0, 2);
					add(i, j, k, l, 0, 3, 0, 0);
					add(i, j, k, l, 0, 2, 1, 0);
					add(i, j, k, l, 0, 2, 0, 1);
					add(i, j, k, l, 0, 1, 2, 0);
					add(i, j, k, l, 0, 1, 1, 1);
					add(i, j, k, l, 0, 1, 0, 2);
					add(i, j, k, l, 0, 0, 3, 0);
					add(i, j, k, l, 0, 0, 2, 1);
					add(i, j, k, l, 0, 0, 1, 2);
					add(i, j, k, l, 0, 0, 0, 3);
				}
			}
		}
	}
	int inv = 1;
	for (int i = 1; i <= 4 * n; i++) {
		inv = (long long)inv * v[i] % p;
	}
	printf("%d\n", (int)((long long)f[0][0][0][0] * inv % p));
	return 0;
}