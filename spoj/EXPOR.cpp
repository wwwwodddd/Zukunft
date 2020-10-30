#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, c[32], x;
typedef unsigned long long ull;
ull ans;
ull d;
ull gcd(ull x, ull y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		memset(c, 0, sizeof c);
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			for (int j = 0; j < 31; j++) {
				if (~x >> j & 1) {
					c[j]++;
				}
			}
		}
		for (int i = 0; i < 31; i++) {
			ans += ((ull)n * (n - 1) / 2 - (ull)c[i] * (c[i] - 1) / 2) << i;
		}
		d = (ull)n * (n - 1) / 2;
		ull g = gcd(d, ans);
		d /= g;
		ans /= g;
		printf("%llu/%llu\n", ans, d);
	}
	return 0;
}