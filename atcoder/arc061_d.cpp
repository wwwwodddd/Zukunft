#include <bits/stdc++.h>
using namespace std;
int n, m, l, p = 1000000007, o = 1, z;
int f[1000020];
int v[1000020];
int t[1000020];
int C(int n, int m) {
	return (long long)f[n] * v[m] % p * v[n - m] % p;
}
int main() {
	scanf("%d%d%d", &n, &m, &l);
	t[0] = f[0] = v[0] = v[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= 1000000; i++) {
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
		t[i] = (long long)t[i - 1] * 3 % p;
	}
	for (int i = 0; i <= m + l; i++) {
		z = (z + (long long)o * C(n + i - 1, n - 1) % p * t[m + l - i]) % p;
		o = o * 2 % p;
		if (i >= m) {
			o = (o + p - C(i, m)) % p;
		}
		if (i >= l) {
			o = (o + p - C(i, l)) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}