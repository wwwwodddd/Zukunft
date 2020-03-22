#include <bits/stdc++.h>
using namespace std;
long long f[1600];
int n;
int main() {
	f[0] = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = n * (n + 1) / 2; j >= i; j--) {
			f[j] += f[j - i];
		}
	}
	if (n * (n + 1) / 2 % 2 == 1) {
		printf("0\n");
	} else {
		printf("%lld\n", f[n * (n + 1) / 2 / 2] / 2);
	}
	return 0;
}