#include <iostream>
#include <cstdio>
using namespace std;
int n = 100;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int calc(int n) {
	long long ans = 0;
	for (long long i = 1; i * i <= 3 * n; i++) {
		for (long long j = 1; j < i && i * i + j * j <= 3 * n; j++) {
			if (i % 2 == 1 && j % 2 == 1) {
				continue;
			}
			if (gcd(i, j) > 1) {
				continue;
			}
			long long x = i * i - j * j;
			long long y = 2 * i * j;
			long long z = i * i + j * j;
			for (long long k = 1; k * z <= 3 * n; k++) {
				long long X = x * k;
				long long Y = y * k;
				long long Z = z * k;
//				printf("??? %lld %lld %lld\n", X, Y, Z);
				for (long long l = 1; 2 * l <= X; l++) {
					if ((Y + l) * (Y + l) + (X - l) * (X - l) >= Z * Z) {
						if (Y <= n && X - l <= n && l <= n) {
							ans++;
//							printf("%lld %lld %lld\n", Y, X - l, l);
						}
					}
				}
				for (long long l = 1; 2 * l <= Y; l++) {
					if ((Y - l) * (Y - l) + (X + l) * (X + l) >= Z * Z) {
						if (Y - l <= n && X <= n && l <= n) {
							ans++;
//							printf("%lld %lld %lld\n", Y - l, X, l);
						}
					}
				}

			}
		}
	}
	return ans;
}
int main() {
	int youqu = 1500;
	while (calc(youqu) <= 1000000) {
		printf("%d\n", youqu);
		youqu++;
	}
	printf("%d\n", youqu);
	return 0;
}