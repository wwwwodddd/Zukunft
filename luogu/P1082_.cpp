#include <bits/stdc++.h>
using namespace std;
long long pw(long long x, long long y, long long p) {
	long long re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
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
int main() {
	int a, b, x, y;
	cin >> a >> b;
	cout << pw(a, phi(b) - 1, b) << endl;
}