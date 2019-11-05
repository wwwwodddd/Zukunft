#include <bits/stdc++.h>
using namespace std;
long long A(long long x, int p) {
	return ((6 * x + 10) % p * x + 3) % p;
}
int F(int p, long long n) {
	n--;
	long long a = 1;
	long long b = 1;
	long long length = 0;
	do {
		a = A(a, p);
		a = A(a, p);
		b = A(b, p);
		length++;
	} while (a != b);
	long long loop = length;
	cout << p << ' ' << loop << endl;
	while ((n - length) % loop != 0) {
		length++;
		b = A(b, p);
	}
	return b;
}
bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
long long B(int l, int r, long long n) {
	r += l;
	long long ans = 0;
	for (int i = l; i <= r; i++) {
		if (isPrime(i)) {
			ans += F(i, n);
			cout << ans << endl;
		}
	}
	return ans;
}
int main() {
	cout << B(1000000000, 10000000, 1000000000000000LL) << endl;
	return 0;
}