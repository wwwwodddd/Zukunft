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
bitset<1500>a[1500], z;
bitset<1500>b[300][300];

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
			if (s[i][j] == '2') {
				continue;
			}
			if (i == 0 || j == 0 || s[i - 1][j] == '2' || s[i][j - 1] == '2' || s[i - 1][j - 1] == '2') {
	//			cerr << i << ' ' << j << ' ' << cnt << endl;
				b[i][j][cnt] = 1;
				c[i][j] = cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			if (s[i][j] == '2') {
				continue;
			}
			if (i == 0 || j == 0 || s[i - 1][j] == '2' || s[i][j - 1] == '2' || s[i - 1][j - 1] == '2') {
			} else {
				b[i][j] = b[i][j - 1] ^ b[i - 1][j] ^ b[i - 1][j - 1];
				b[i][j][cnt] = b[i][j][cnt] ^ (s[i][j] ^ s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == -1) {
				continue;
			}
			a[c[i][j]] = b[i][j];
			for (int d = 0; d < 4; d++) {
				for (int k = 1;; k++) {
					int x = i + dx[d] * k;
					int y = j + dy[d] * k;
					if (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '2') {
						a[c[i][j]] ^= b[x][y];
					} else {
						break;
					}
				}
			}
			a[c[i][j]][cnt] = a[c[i][j]][cnt] ^ (s[i][j] - '0');
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
			printf("%lu", (z & b[i][j]).count() & 1);
		}
		printf("\n");
	}
//	printf("\n");
	return 0;
}