#include <bits/stdc++.h>
using namespace std;
int n, k, s, x;
long long f[2020];
int main() {
	scanf("%d%d", &n, &k);
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (i == 1) {
			f[1] = 1;
		} else {
			for (int j = i; j > 0; j--) {
				f[j] = min(f[j], f[j - 1] + x * f[j - 1] / s + 1);
			}
		}
		s += x;
	}
	if (s == k) {
		printf("%d\n", 1);
	} else {
		for (int i = n; i >= 0; i--) {
			if (f[i] <= k) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}