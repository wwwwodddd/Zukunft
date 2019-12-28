#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[10001][201];
int p[10001], x, y, d;
int main() {
	memset(f, 0x3f3f3f3f, sizeof f);
	memset(p, 0x3f3f3f3f, sizeof p);
	scanf("%d", &d);
	int index = 1;
	while (scanf("%d %d", &x, &y) != EOF) {
		p[x] = y;
	}
	f[0][100] = 0;
	for (int i = 0; i <= d; i++) {
		if (p[i] != -1) {
			for (int j = 0; j < 200; j++) {
				f[i][j + 1] = min(f[i][j + 1], f[i][j] + p[i]);
			}
		}
		if (i < d) {
			for (int j = 0; j < 200; j++) {
				f[i + 1][j] = f[i][j + 1];
			}
		}
	}
	if (f[d][100] != 0x3f3f3f3f) {
		printf("%d\n", f[d][100]);
	} else {
		printf("Impossible\n");
	}
	return 0;
}
