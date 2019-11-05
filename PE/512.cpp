#include <iostream>
#include <cstdio>
using namespace std;
int f[500000020];
int n = 500000000;
int main() {
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		if (f[i] == i) {
			for (int j = i; j <= n; j += i) {
				f[j] = f[j] / i * (i - 1);
			}

		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i += 2) {
		ans += f[i];
	}
	printf("%lld\n", ans);
	return 0;
}