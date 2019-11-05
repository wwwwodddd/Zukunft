#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long ans;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
long long a[10000];
int main() {
	a[0] = 1;
	a[1] = 4;
	for (int i = 2; i < 20; i++) {
		a[i] = 4 * a[i - 1] + a[i - 2];
	}
	for (int i = 0 ; i < 12; i++) {
		ans += a[i] * a[i] + a[i + 1] * a[i + 1];
	}
	/*
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
			if (abs(b - 2 * a) == 1 || abs(a - 2 * b) == 1) {
				printf("%d %d %d %d %d\n", a, b, c, i, j);
				ans += c;
			}
		}
	}
	*/
	printf("%lld\n", ans);
	return 0;
}