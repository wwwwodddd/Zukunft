//  http://oeis.org/A002464
#include <bits/stdc++.h>
using namespace std;
int t, n, p = 1000000007;
long long f[10000020];
int main() {
	f[0] = f[1] = 1;
	for (int i = 4; i <= 10000000; i++) {
		f[i] = ((i + 1) * f[i - 1] - (i - 2) * f[i - 2] - (i - 5) * f[i - 3] + (i - 3) * f[i - 4]) % p;
		if (f[i] < 0) {
			f[i] += p;
		}
	}
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}