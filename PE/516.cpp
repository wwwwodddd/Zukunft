#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
bool P(long long x) {
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

long long a[10000];
long long n = 1000000000000LL;
int cnt = 0;
long long sum;
void dfs(long long x, int y) {
//	printf("%lld %d\n", x, y);
	for (long long i = x; i <= n; i *= 2) {
		for (long long j = i; j <= n; j *= 3) {
			for (long long k = j; k <= n; k *= 5) {
				sum += k;
//				printf("%lld\n", k);
			}
		}
	}
	for (int i = y; i < cnt; i++) {
		if (y == 0) {
			printf("%d\n", i);
		}
		if (x <= n / a[i]) {
			dfs(x * a[i], i + 1);
		}
	}
}
int main() {
	for (long long i = 1; i <= n; i *= 2) {
		for (long long j = i; j <= n; j *= 3) {
			for (long long k = j; k <= n; k *= 5) {
				if (k + 1 != 2 && k + 1 != 3 && k + 1 != 5) {
					if (P(k + 1)) {
						a[cnt++] = k + 1;
					}
				}
			}
		}
	}
	sort(a, a + cnt);
//	for (int i = 0; i < cnt; i++) {
//		printf("%d\n", a[i]);
//	}
	printf("%d\n", cnt);
	dfs(1, 0);
	printf("%d\n", (int)sum);
	return 0;
}