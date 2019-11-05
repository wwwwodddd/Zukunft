#include <bits/stdc++.h>
using namespace std;
int v[10101010];
long long p[100100];
int pc, mod = 1000000000;
long long fuck(long long l, long long r) {
	memset(v, 0, sizeof v);
	for (int i = 0; i < pc && p[i] * p[i] <= r; i++) {
		for (long long j = (l - 1) / p[i] * p[i] + p[i]; j <= r; j += p[i]) {
			if (v[j - l] == 0) {
				v[j - l] = p[i];
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= r - l; i++) {
		if (v[i] > 0) {
			sum += v[i];
			sum %= mod;
		} else {
			sum += i + l;
			sum %= mod;
		}
	}
	return sum;
}
int main() {
	for (int i = 2; i <= 1000020; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= 1000020; j += i) {
			v[j] = i;
		}
	}
	long long n = 1e12;
	long long l = 0;
	long long r = 0;
	long long ans = -1;
	while (true) {
		l = r + 1;
		r += 10000000;
		r = min(r, n);
		if (r % 100000000 == 0) {
			cerr << l << ' ' << r << endl;
		}
		ans += fuck(l, r);
		ans %= mod;
		if (r == n) {
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
