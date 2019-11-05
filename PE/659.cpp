#include <bits/stdc++.h>
using namespace std;
int p[20000200], pc;
int v[20000200];
long long mod = 1e18;
long long F(long long k) {
	long long z = k * k * 4 + 1;
	long long re = 0;
	for (int i = 0; (long long)p[i] * p[i] <= z; i++) {
		while (z % p[i] == 0) {
			z /= p[i];
			re = p[i];
		}
	}
	if (z > 1) {
		re = z;
	}
	return re;
}
void init(int n) {
	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (v[i] == i) {
			p[pc++] = i;
			for (int j = i; j <= n; j += i) {
				v[j] = i;
			}
		}
	}
	cerr << pc << endl;
}
int main() {
	int n = 10000000;
	init(2 * n + 100);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 100000 == 0) {
			cerr << i << ' ' << ans << endl;
		}
		ans = (ans + F(i)) % mod;
	}
	cout << ans << endl;
	return 0;
}