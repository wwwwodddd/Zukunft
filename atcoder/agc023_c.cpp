#include <bits/stdc++.h>
using namespace std;
long long n, p = 1000000007, z;
int f[1000020];
int v[1000020];
int main() {
	cin >> n;
	f[0] = v[0] = v[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= 1000000; i++) {
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
	}
	for (int i = (n + 1) / 2; i < n; i++) {
		z = (z + (long long)f[i] * f[i - 1] % p * v[2 * i - n]) % p;
	}
	cout << (f[n] + p - z) % p << endl;
	return 0;
}