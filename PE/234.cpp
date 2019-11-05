#include <bits/stdc++.h>
using namespace std;
//long long n = 999966663333LL;
long long n = 999966663333;
int v[2000020];
long long p[2000020];
int pc;
int main() {
	for (int i = 2; i < 2000000; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j < 2000000; j += i) {
			v[j] = i;
		}
	}
	long long ans = 0;
	for (int i = 0; i < pc - 1; i++) {
		if ((long long)p[i + 1] * p[i + 1] > n) {
			long long a = (n - p[i] * p[i]) / p[i];
			long long b1 = n / p[i + 1];
			long long b2 = p[i] * p[i] / p[i + 1];
			ans += (p[i] * p[i] + p[i] * p[i] + a * p[i] + p[i]) * a / 2;
			ans += b1 * (b1 + 1) / 2 * p[i + 1];
			ans -= b2 * (b2 + 1) / 2 * p[i + 1];
			cout << p[i] << ' ' << p[i + 1] << ' ' << a << ' ' << b1 << ' ' << b2 << endl;
			if (p[i] * p[i + 1] <= n) {
				ans -= p[i] * p[i + 1];
				ans -= p[i] * p[i + 1];
			}
			break;
		} else {
			long long a = (p[i + 1] * p[i + 1] - p[i] * p[i]) / p[i];
			ans += (p[i] * p[i] + p[i] * p[i] + a * p[i] + p[i]) * a / 2;
			long long b = (p[i + 1] * p[i + 1] - p[i] * p[i]) / p[i + 1];
			ans += (p[i + 1] * p[i + 1] - b * p[i + 1] + p[i + 1] * p[i + 1] - p[i + 1]) * b / 2;
			ans -= p[i] * p[i + 1];
			ans -= p[i] * p[i + 1];
			cout << p[i] << ' ' << p[i + 1] << ' ' << a << ' ' << b << ' ' << ans << endl;
		}
	}
	printf("%lld\n", ans);
	printf("%lld %lld\n", n, (long long)p[pc - 1] * p[pc - 1]);
	return 0;
}