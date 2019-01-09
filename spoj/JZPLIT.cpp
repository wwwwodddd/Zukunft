#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <bitset>
using namespace std;
int n, m, l, t;
char s[1020][1020];
int c[1020][1020], cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bitset<2000>a[2000], z, v, h;

int main() {
	scanf("%d%d", &n, &m);
	l = n * m;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	memset(c, -1, sizeof c);
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			if (i == 0 || j == 0) {
				c[i][j] = cnt++;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		v[c[k][0]] = 1;
	}
	for (int k = 0; k < m; k++) {
		h[c[0][k]] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != 0 && j != 0) {
				continue;
			}
			a[c[i][j]] = v ^ h;
			a[c[i][j]][c[i][0]] = a[c[i][j]][c[i][0]] ^ 1;
			a[c[i][j]][c[0][j]] = a[c[i][j]][c[0][j]] ^ 1;
			a[c[i][j]][c[i][j]] = a[c[i][j]][c[i][j]] ^ 1;
			int t = 0;
			for (int k = 0; k < n; k++) {
				if (k == i) {
					continue;
				}
				t ^= s[k][j] ^ s[k][0] ^ s[0][j] ^ s[0][0];

			}
			for (int k = 0; k < m; k++) {
				if (k == j) {
					continue;
				}
				t ^= s[i][k] ^ s[i][0] ^ s[0][k] ^ s[0][0];
			}
			if ((n - 1) % 2) {
				a[c[i][j]][c[0][j]] = a[c[i][j]][c[0][j]] ^ 1;
			}
			if ((m - 1) % 2) {
				a[c[i][j]][c[i][0]] = a[c[i][j]][c[i][0]] ^ 1;
			}
			if ((n + m) % 2) {
				a[c[i][j]][c[0][0]] = a[c[i][j]][c[0][0]] ^ 1;
			}
			t ^= s[i][j] - '0';
			a[c[i][j]][cnt] = t;
		}
	}
	t = 0;
//	cerr << n << ' ' << m << ' ' << cnt << endl;
	/*
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j <= cnt; j++) {
			printf("%d", (int)a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k <= cnt; k++) {
				printf("%d", (int)b[i][j][k]);
			}
			printf("\n");
		}
	}
	*/
	for (int i = 0; i < cnt; i++) {
		int k = t;
		for (int j = t; j < cnt; j++) {
			if (a[j][i] != 0) {
				k = j;
			}
		}
		swap(a[k], a[t]);
		if (a[t][i] == 0) {
			continue;
		}
		for (int j = 0; j < cnt; j++) {
			if (t != j && a[j][i] == 1) {
				a[j] ^= a[t];
			}
		}
		t++;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (a[i][j] == 1) {
				z[j] = a[i][cnt];
				break;
			}
		}
	}
	z[cnt] = 1;
	/*
	for (int i = 0; i <= cnt; i++) {
		printf("%d", (int)z[i]);
	}
	printf("\n");
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", (z[c[0][0]] ^ z[c[0][j]] ^ z[c[i][0]] ^ s[0][0] ^ s[0][j] ^ s[i][0] ^ s[i][j]));
		}
		printf("\n");
	}
//	printf("\n");
	return 0;
}