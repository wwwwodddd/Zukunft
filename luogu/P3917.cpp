#include <bits/stdc++.h>
using namespace std;
int n, x;
long long f[32], z;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < 30; j++) {
			if (x >> j & 1) {
				f[j] = i - f[j];
			}
			z += f[j] << j;
		}
	}
	printf("%lld\n", z);
	return 0;
}