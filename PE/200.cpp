#include <bits/stdc++.h>
using namespace std;
int v[10000020];
int p[10000020], pc;
long long a[10000020];
int c;
bool check(long long x) {
	while (x > 0) {
		if (x % 1000 == 200) {
			return true;
		}
		x /= 10;
	}
	return false;
}

bool nimabi(long long x) {
	if (x < 2) {
		return false;
	}
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
bool caonima(long long x) {
	int a[20], c = 0;
	while (x > 0) {
		a[c++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < c; i++) {
		int now = a[i];
		for (a[i] = 0; a[i] < 10; a[i]++) {
			long long x = 0;
			for (int j = c - 1; j >= 0; j--) {
				x = 10 * x + a[j];
			}
			if (nimabi(x)) {
				return false;
			}
		}
		a[i] = now;
	}
	return true;
}
int main() {
	int n = 1000000;
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}

	for (int i = 0; i < pc; i++) {
		for (int j = 0; j < pc; j++) {
 			if ((long long)p[j] * p[j] * p[j] > 1000000000000LL / p[i] / p[i]) {
				break;
			}
			if (i == j) {
				continue;
			}
			long long x = (long long)p[i] * p[i] * p[j] * p[j] * p[j];
			if (check(x) && caonima(x)) {
				printf("%d %d %lld\n", p[i], p[j], x);
				a[c++] = x;
			}
		}
	}
	sort(a, a + c);
	printf("%d\n", c);
	printf("%lld\n", a[1]);
	printf("%lld\n", a[199]);
	return 0;
}