#include <bits/stdc++.h>
using namespace std;

int pow(long long x, int y, int p) {
	long long re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return (int)re;
}
int v[10000020];
int d[10];
int n = 10000000;
int main() {
	d[1] = 9;
	d[3] = 3;
	d[7] = 7;
	d[9] = 1;
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		if (i != 2 && i != 5) {
			int tmp = ((long long)i * d[i % 10] + 1) / 10;
			ans += tmp;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}