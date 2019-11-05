#include <bits/stdc++.h>
using namespace std;
int n = 100000000;
int v[100000020];
int f[100000020];
int pw(int x, int y, int p) {
	int re = 1;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}

int calc(int x) {
	while (x % 2 == 0) {
		x /= 2;
	}
	while (x % 5 == 0) {
		x /= 5;
	}
	if (x == 1) {
		return 0;
	}
	int re = f[x];
//	if (pw(10, re, x) > 1) {
//		cerr << re << ' ' << x << endl;
//	}
	assert(pw(10, re, x) == 1);
	int u = re;
	while (u > 1) {
		if (pw(10, re / v[u], x) == 1) {
			re /= v[u];
		}
		u /= v[u];
	}
	return re;
}
int main() {
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = f[i / v[i]] * v[i];
		} else {
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 1000000 == 0) {
			cerr << i << endl;
		}
		ans += calc(i);
	}
	printf("%lld\n", ans);
	return 0;
}