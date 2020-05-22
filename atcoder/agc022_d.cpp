#include <bits/stdc++.h>
using namespace std;
int n, l, c0, c1, c2;
long long z;
int x[300020];
int t[300020];
int f[300020];
int main() {
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	z = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		z += t[i] / (2 * l);
		t[i] %= 2 * l;
		if (t[i] > 0) {
			z++;
			int f = (t[i] <= (l - x[i]) * 2);
			int g = (t[i] <= (x[i]) * 2);
			if (i == n - 1) {
				if (f) {
					z--;
				}
				break;
			}
			if (g) {
				c0++;
				if (f) {
					c2++;
				}
			} else if (f) {
				c1++;
			}
			while (c0 - c2 < c1 + c2) {
				if (c2 > 0) {
					c2--;
				} else {
					c1--;
				}
			}
		}
	}
	z -= c1 + c2;
	printf("%lld\n", z * l * 2);
	return 0;
}