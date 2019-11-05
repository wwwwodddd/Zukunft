#include <iostream>
#include <cstdio>
using namespace std;
int f[100000020];
long long v[10];
int n = 100000000;
int main() {
	for (int i = 2; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		if (f[i] == 0) {
			for (int j = 2 * i; j <= n; j += i) {
				f[j] = 1;
			}
		}
	}
	long long ans = 0;
	for (int i = 5; i <= n; i++) {
		if (f[i] == 0) {
			v[1] = 1;
			for (int j = 2; j <= 5; j++) {
				v[j] = v[i % j] * (i - i / j) % i;
			}
			long long tmp = i - 1;
			long long uvi = 0;
			for (int j = 1; j <= 5; j++) {
				uvi += tmp;
				tmp = tmp * (i - v[j]) % i;
			}
			ans += uvi % i;
		} 
	}
	printf("%lld\n", ans);
	return 0;
}