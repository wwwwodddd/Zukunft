#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long a[1020][1020];
long long s[1020][1020];
long long ans = 0;
int next() {
	static int t = 0;
	t = 615949 * t + 797807;
	t = t & 0xfffff;
	return t - (1 << 19);
}
int main() {
	int n = 1000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j] = next();
		}
		reverse(a[i] + 1, a[i] + 1 + n);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			if (ans > s[i][j]) {
				ans = s[i][j];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}