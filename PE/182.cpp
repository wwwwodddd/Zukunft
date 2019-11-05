#include <bits/stdc++.h>
using namespace std;

int p = 1009, q = 3643, phi = (p - 1) * (q - 1);
long long ans = 0;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int main() {
	for (int i = 2; i < phi; i++) {
		if (gcd(i, phi) > 1) {
			continue;
		}
		if (gcd(i - 1, p - 1) * gcd(i - 1, q - 1) == 4) {
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}