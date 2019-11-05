// DNF
#include <iostream>
#include <cstdio>
using namespace std;
int f[150000020];
int p[30] = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
int n = 150000000;
int main() {
	for (int i = 2; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		if (f[i] == 0) {
			for (int j = 2 * i; j <= n; j += i) {
				f[i] = 1;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i * i + 27 <= n; i++) {
		int same = true;
		for (int j = 0; j < 28; j++) {

		}
		if (same)
	}
	printf("%lld\n", ans);
	return 0;
}