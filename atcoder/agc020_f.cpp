#include <bits/stdc++.h>
using namespace std;
double z, f[320][33], t;
int n, c, a[9];
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	do {
		memset(f, 0, sizeof f);
		f[n * a[n - 1]][0] = 1;
		for (int i = 0; i < n * c; i++) {
			for (int j = i; j <= n * c; j++) {
				for (int k = 0; k < (1 << (n - 1)); k++) {
					if (i % n && (k >> (i % n - 1) & 1) == 0) {
						f[min(max(j, i + n * a[i % n - 1]), n * c)][k | (1 << (i % n - 1))] += f[j][k];
					}
				}
			}
		}
		z += f[n * c][(1 << (n - 1)) - 1];
		t++;
	} while (next_permutation(a, a + n - 1));
	printf("%.15f\n", z / t / pow(c, n - 1));
	return 0;
}