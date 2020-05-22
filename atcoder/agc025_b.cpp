#include <bits/stdc++.h>
using namespace std;
long long n, a, b, k, p = 998244353, z;
int f[1000020];
int v[1000020];
int C(int n, int m) {
	return (long long)f[n] * v[m] % p * v[n - m] % p;
}
int main() {
	cin >> n >> a >> b >> k;
	f[0] = v[0] = v[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= 1000000; i++) {
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
	}
	for (int i = 0; i <= n; i++) {
		int j = (k - a * i) / b;
		if (0 <= j && j <= n && i * a + j * b == k) {
			z = (z + (long long)C(n, i) * C(n, j)) % p;
		}
	}
	cout << z << endl;
	return 0;
}