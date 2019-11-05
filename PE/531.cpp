#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
long long gcd(long long x, long long y, long long &a, long long &b) {
	if (y == 0) {
		a = 1;
		b = 0;
		return x;
	}
	long long g = gcd(y, x % y, b, a);
	b -= x / y * a;
	return g;
}

long long g(long long a, long long n, long long b, long long m) {
	long long u, v;
	long long g = gcd(n, m, u, v);
	long long lcm = n / g * m;
	if ((a - b) % g != 0) {
		return 0;
	}
	long long t = ((b - a) / g * n * u + a) % lcm;
	if (t < 0) {
		t += lcm;
	}
	assert(t % n == a && t % m == b);
	return t;
}

int phi(int x) {
	int re = x;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			re = re / i * (i - 1);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		re = re / x * (x - 1);
	}
	return re;
}
int f[5000];
int main() {
	for (int i = 1000000; i < 1005000; i++) {
		f[i - 1000000] = phi(i);
		printf("%d %d\n", i, f[i - 1000000]);
	}
	unsigned long long ans = 0;
	for (int i = 0; i < 5000; i++) {
		for (int j = i + 1; j < 5000; j++) {
			ans += g(f[i], i + 1000000, f[j], j + 1000000);
		}
//		printf("%llu\n", ans);
	}
	printf("%llu\n", ans);
	return 0;
}