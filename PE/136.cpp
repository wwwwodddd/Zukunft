#include <iostream>
#include <cstdio>
using namespace std;
int v[50000020];
int main() {
	for (long long z = 1; z < 50000000; z++) {
		long long L = 0;
		long long R = 50000000;
		while (L < R - 1) {
			long long M = (L + R) >> 1;
			if (2 * M * z + 3 * M * M - z * z > 0) {
				R = M;
			} else {
				L = M;
			}
		}
		for (long long d = R;; d++) {
			if (2 * d * z + 3 * d * d - z * z >= 50000000) {
				break;
			}
			v[2 * d * z + 3 * d * d - z * z] += 1;
		}
	}
/*
	for (long long i = 1; i <= 50000000; i++) {
		for (long long j = min(i * 4 / 5 + 100, i - 1); j > 0; j--) {
			if (2 * j - i <= 0) {
				break;
			}
			long long diff = i * i - j * j - (2 * j - i) * (2 * j - i);
			if (diff > 50000000) {
				break;
			}
			if (diff > 0) {
				v[diff] += 1;
			}
		}
	}
*/
	int ans = 0;
	for (int i = 1; i < 50000000; i++) {
		if (v[i] == 1) {
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}