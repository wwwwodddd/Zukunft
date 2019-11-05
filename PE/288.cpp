#include <iostream>
#include <cstdio>
using namespace std;
int n = 10000000;
long long s[10000020];
int p = 50515093;
long long mod = 713342911662882601LL;
int main() {
	s[0] = 290797;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] * s[i - 1] % p;
	}
	for (int i = 0; i <= n; i++) {
		s[i] %= 61;
	}
	for (int i = n - 1; i >= 0; i--) {
		s[i] += s[i + 1];
		s[i] %= mod;
	}
	long long ans = 0;
	long long tmp;
	for (int i = n; i > 0; i--) {
		tmp = 0;
		for (int j = 0; j < 61; j++) {
			tmp += ans;
			if (tmp >= mod) {
				tmp -= mod;
			}
		}
		ans = tmp + s[i];
		if (ans >= mod) {
			ans -= mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}