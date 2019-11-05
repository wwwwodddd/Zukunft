#include <iostream>
#include <cstdio>
using namespace std;
int n = 1000000000;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	long long ans = 0;
	for (long long i = 1; 2 * i * i <= n; i++) {
		for (long long j = 1; j < i && 2 * i * i + 2 * i * j <= n; j++) {
			if (i % 2 == 1 && j % 2 == 1) {
				continue;
			}
			if (gcd(i, j) > 1) {
				continue;
			}
			long long x = i * i - j * j;
			long long y = 2 * i * j;
			long long z = i * i + j * j;
			if (x > y) {
				swap(x, y);
			}
			if (abs(2 * x - z) == 1) {
				ans += 2 * x + 2 * z;
				printf("%lld %lld %lld\n", x, y, z);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}