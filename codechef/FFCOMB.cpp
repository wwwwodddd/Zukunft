#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int t, n, m;
int f[1 << 20];
int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < 1 << n; i++) {
			f[i] = 0x3f3f3f3f;
		}
		f[0] = 0;
		for (int i = 0; i < n; i++) {
			int c;
			scanf("%d", &c);
			f[1 << i] = min(f[1 << i], c);
		}
		for (int i = 0; i < m; i++) {
			int p, q, s = 0, x;
			scanf("%d%d", &p, &q);
			for (int j = 0; j < q; j++) {
				scanf("%d", &x);
				s |= 1 << (x - 1);
			}
			f[s] = min(f[s], p);
		}
		for (int i = 0; i < 1 << n; i++) {
			for (int j = i; j > 0; j = (j - 1) & i) {
				f[j] = min(f[j], f[i]);
			}
		}
		for (int i = 0; i < 1 << n; i++) {
			for (int j = i; j > 0; j = (j - 1) & i) {
				f[i] = min(f[i], f[j] + f[i ^ j]);
			}
		}
		printf("%d\n", f[(1 << n) - 1]);
	}
	return 0;
}