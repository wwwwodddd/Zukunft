#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long ans = 0;
int main() {
	n = 1000000000;
	n--;
	for (int i = 0; i <= n; i++) {
		if (i % 10000000 == 0) {
			printf("%d\n", i);
		}
		long long mul = 1;
		int t = i;
		while (t > 0) {
			mul *= t % 7 + 1;
			t /= 7;
		}
		ans += mul;
	}
	printf("%lld\n", ans);
	return 0;
}