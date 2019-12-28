#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;
int n, m, x;
int main() {
	for (; scanf("%d%d", &n, &m), n + m;) {
		bitset<100001>f[2], q;
		f[0][0] = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			q = f[0];
			f[0] |= f[1] << x;
			f[1] |= q << x;
		}
		int z = 0;
		for (int i = 0; i <= m; i++) {
			if (f[1][i] && !f[0][i]) {
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}