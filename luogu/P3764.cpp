#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int F(int x, int y) {
	int g = gcd(x, y);
	x /= g;
	y /= g;
	int s = x + y;
	for (int i = 0; (1 << i) <= s; i++) {
		if ((1 << i) == s) {
			return i - 1;
		}
	}
	return 0;
}

long long solve1(long long n) {
	long long re = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			re += F(i, j);
		}
	}
	return re;
}

long long calc(long long x) {
	for (int i = 0;; i++) {
		if (1LL << i >= x) {
			return i - 1;
		}
	}
}
long long solve2(long long n) {
	long long re = 0;
	for (int i = 3; i <= n; i += 2) {
		int coef = calc(i);
		re += n / i * coef;
	}
	return re * 2;
}

long long work(long long n, long long l, long long r) {
	long long re = 0;
	while (l <= r) {
		long long coef = calc(l);
		long long upper = (2LL << coef) - 1;
		if (upper > r) {
			upper = r;
		}
		re += n / l * coef * ((upper - l + 2) / 2);
		l = upper + 2;
	}
	return re;
}
long long solve3(long long n) {
	long long re = 0;
	for (long long i = 3; i <= n; i += 2) {
//		cout << i << endl;
		long long right = n / (n / i);
		if (right % 2 == 0) {
			right--;
		}
		long long coef = calc(i);
		re += work(n, i, right);
		i = right;
	}
	return re * 2;
}

int main() {
	long long n;
	scanf("%lld", &n);
//	cout << solve1(n) << endl;
//	cout << solve2(n) << endl;
	cout << solve3(n) << endl;
	return 0;
}