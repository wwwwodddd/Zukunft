#include <stdio.h>
#include <iostream>
using namespace std;
int v[1000020];
int p[1000020];
int c[100020];
typedef long long ll;
ll mod = 10000000000000061;
ll f[2][100020];
int ttt = 100000;
int n, m, pc;
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= n; j += i) {
				v[j] = i;
			}
			p[pc++] = i;
			m = n;
			for (m /= i; m; m /= i) {
				c[pc - 1] += m;
			}
		}
	}
	f[0][1] = 1;
	for (int i = 0; i < pc; i++) {
		fprintf(stderr, "%d/%d\n", i, pc);
		memset(f[i + 1 & 1], 0, sizeof f[0]);
		for (int k = 0; k < ttt; k++) {
			if (k % 1000 == 0) {
				fprintf(stderr, "%d/%d %d\n", i, pc, k);
			}
			if (f[i & 1][k] == 0) {
				continue;
			}
			int q = k;
			for (int j = 0; j <= c[i]; j++, q = (long long)q * p[i] % ttt) {
				if (j % 1000 == 0) {
					fprintf(stderr, "%d/%d %d %d\n", i, pc, k, j);
				}
				f[i + 1 & 1][q] += f[i & 1][k];
//				printf("%d %d %d %lld\n", k, i + 1, q, f[i + 1 & 1][q]);
				if (f[i + 1 & 1][q] >= mod) {
					f[i + 1 & 1][q] -= mod;
				}
			}
		}
	}
	printf("%lld\n", f[pc & 1][65432]);
	return 0;
}