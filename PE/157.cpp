#include <iostream>
#include <cstdio>
using namespace std;
int calc(long long x) {
	int cnt = 0;
	for (long long i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			cnt++;
			if (i * i < x) {
				cnt++;
			}
		}
	}
	return cnt;
}

long long gcd(long long x, long long y) {
	return y ? gcd(y, x % y) : x;
}

int solve(int n) {
	int ans = 0;
	int ten = 1;
	for (int i = 0; i < n; i++) {
		ten *= 10;
	}
	n *= 2;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			long long a = 1;
			long long b = 1;
			for (int k = 0; k < i; k++) {
				a *= 2;
			}
			for (int k = i; k < n; k++) {
				b *= 2;
			}
			for (int k = 0; k < j; k++) {
				a *= 5;
			}
			for (int k = j; k < n; k++) {
				b *= 5;
			}
			a += ten;
			b += ten;
			if (a > b) {
				continue;
			}
			int t = calc(gcd(a, b));
//			printf("%lld %lld %d\n", a, b, t);
			ans += t;
		}
	}
	return ans;
}

int main() {
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += solve(i);
	}
	printf("%d\n", ans);
	return 0;
}