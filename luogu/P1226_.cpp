#include <bits/stdc++.h>
using namespace std;

long long gao(long long b, long long p, long long k) {// b的p次方mod k
	if (p == 0) { // b^0 = 1
		return 1 % k; // k 可能为 1 
	} else if (p % 2 == 0) { // p % 2 == 0
	// 2种写法 
	// pow(b, p) = pow(b*b, p/2) 
	// pow(b, p) = (pow(b, p/2))^2
		long long r = gao(b, p / 2, k);
		return r * r % k;
	} else { // p % 2 == 1
	// pow(b, p) = pow(b, p - 1) * b 
		return gao(b, p - 1, k) * b % k;
	}
}
long long pw(long long x, long long y, long long p) {
//	1. p = 1
//  2. x > p
//  3. y < 0 一般是写错了
	x %= p;
	long long re = 1 % p;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}

long long b, p, k;
int main() {
	cin >> b >> p >> k;
	printf("%lld^%lld mod %lld=%lld\n", b, p, k, pw(b, p, k));
	return 0;
}

