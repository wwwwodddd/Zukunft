#include <iostream>
#include <cstdio>
using namespace std;
int n = 100000000;
int v[100000020];
int m[100000020];
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	m[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == v[i / v[i]]) {
			m[i] = 0;
		} else {
			m[i] = -m[i / v[i]];
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long u = n / i - 1;
		ans += u * (u + 1) / 2 * m[i];
	}
	ans = (long long)n * (n + 1) / 2 - 1 - ans;
	ans *= 6;
	printf("%lld\n", ans);
	return 0;
}