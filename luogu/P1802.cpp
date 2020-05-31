#include <bits/stdc++.h>
using namespace std;
int n, m, s, x, y, z, f[1020];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		s += x;
		for (int j = m; j >= z; j--) {
			f[j] = max(f[j], f[j - z] + y - x);
		}
	}
	printf("%lld\n", (f[m] + s) * 5LL);
	return 0;
}