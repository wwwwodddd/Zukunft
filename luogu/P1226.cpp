#include <bits/stdc++.h>
using namespace std;

long long gao(long long b, long long p, long long k) {// b的p次方mod k
	if (p == 0) {
		return 1 % k;
	} else if (p % 2 == 0) {
		long long r = gao(b, p / 2, k);
		return r * r % k;
	} else {
		return gao(b, p - 1, k) * b % k;
	}
}
long long b, p, k;
int main() {
	cin >> b >> p >> k;
	printf("%lld^%lld mod %lld=%lld\n", b, p, k, gao(b, p, k));
	return 0;
}


