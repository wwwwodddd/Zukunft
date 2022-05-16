#include <iostream>
#include <cstdio>
using namespace std;
const int p = 10000009;
long long f[2 * p];
int t;
long long n;
int main() {
	f[0] = 1;
	for (int i = 2; i < 2 * p; i++) {
		f[i] = (f[i - 1] + f[i - 2]) * (i - 1) % p;
	}
	for(scanf("%d", &t); t--;) {
		scanf("%lld", &n);
		printf("%lld\n", n % p * f[(n - 1) % (2 * p)] % p);
	}
}