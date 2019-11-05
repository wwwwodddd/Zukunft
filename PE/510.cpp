#include <bits/stdc++.h>
using namespace std;
long long v[2500000020];

int n = 10000000;

bool sqfree(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % (i * i) == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	n = 1000000000;

	for (int i = 2; i * i <= 250000000; i++) {
		for (int j = i * i; j <= 250000000; j += i * i) {
			v[j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) {
			v[i] = 0;
		} else {
			v[i] = i;
		}
		v[i] += v[i - 1];
	}
	long long ans = 0;
	for (int y = 1; y <= n; y++) {
		if (y % 1000 == 0) {
			cerr << y << ' ' << ans << endl;
		}
		for (int x = 1; x <= y; x++) {
			long long p = sqrt((long long)x * y + 0.5);
			if (p * p != x * y) {
				continue;
			}
			if ((y + p) * (y + p) > n) {
				break;
			}
			long long t = (x + p) * (x + p) + (y + p) * (y + p) + (long long)x * y;
			long long r = n / ((y + p) * (y + p));
			ans += v[r] * t;
		}
	}
	cout << n << ' ' << ans << endl;
	return 0;
}