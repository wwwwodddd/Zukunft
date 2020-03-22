#include <bits/stdc++.h>
using namespace std;
int n, p = 100000007;
int inv[100020];
int main() {
	cin >> n;
	inv[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		inv[i] = (long long)(p - p / i) * inv[p % i] % p;
	}
	long long z = 1;
	for (int i = 0; i < n; i++) {
		z = z * (2 * n - i) % p * inv[i + 1] % p;
	}
	z = z * inv[n + 1] % p;
	cout << z << endl;
}