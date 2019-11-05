#include <bits/stdc++.h>
using namespace std;

bitset<200000000>v;
int p[10000020], pp;
int mod = 10007;
int c[100020];
int t = 30000;
void R(int x, int y) {
	x++;
	for (; x <= t; x += x & -x) {
		c[x] += y;
	}
}

int G(int x) {
	int re = 0;
	for (; x; x -= x & -x) {
		re += c[x];
	}
	return re;
}

int A(int x) {
	int re = 0;
	for (int i = 16; i >= 0; i--) {
		if (re + (1 << i) <= t && x > c[re + (1 << i)]) {
			x -= c[re += (1 << i)];
		}
	}
	return re;
}
int pw(int x, int y) {
	int re = 1;
	x %= mod;
	for (; y; y >>= 1) {
		if (y & 1) {
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
int main() {
	int n = 10000000;
	int m = 100000;
	for (int i = 2; i < 200000000; i++) {
		if (v[i]) {
			continue;
		}
		p[++pp] = i;
		if (pp == n) {
			break;
		}
		for (int j = i + i; j < 200000000; j += i) {
			v[j] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i] = pw(p[i], i);
	}
	for (int i = n; i > 0; i--) {
		p[i] += p[i / 10000 + 1];
	}
	for (int i = 1; i < m; i++) {
		R(p[i], 1);
	}
	long long ans = 0;
	for (int i = m; i <= n; i++) {
		R(p[i], 1);
		ans += A(m / 2) + A(m / 2 + 1);
		R(p[i - m + 1], - 1);
	}
	printf("%lld", ans / 2);
	if (ans % 2) {
		printf(".5\n");
	} else {
		printf(".0\n");
	}
}