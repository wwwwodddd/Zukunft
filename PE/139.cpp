#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long ans;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	int n = 100000000;
	n -= 1;
	for (int i = 1; i * i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) > 1) {
				continue;
			}
			if (i % 2 == 1 && j % 2 == 1) {
				continue;
			}
			int a = i * i - j * j;
			int b = 2 * i * j;
			int c = i * i + j * j;
			if (c % abs(a - b) == 0) {
				printf("%d %d %d\n", a, b, c);
				ans += n / (a + b + c);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}