#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int v[1000300];
int n = 1000200;
long long exgcd(long long x, long long y, long long &a, long long &b) {
	if (y == 0) {
		a = 1;
		b = 0;
		return x;
	}
	long long g = exgcd(y, x % y, b, a);
	b -= x / y * a;
	return g;
}
int p[1000020], pc;
long long ans;
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		if (i > 1000000) {
			break;
		}
		for (int j = i + i; j <= n; j += i) {
			v[j] = 1;
		}
	}

	for (int i = 2; i < pc - 1; i++) {
		long long ten = 1;
		while (ten < p[i]) {
			ten *= 10;
		}
		long long a, b;
		exgcd(ten, p[i + 1], a, b);
		b *= p[i];
		b %= ten;
		if (b < 0) {
			b += ten;
		}
		ans += b * p[i + 1];
	}
	printf("%lld\n", ans);
	return 0;
}