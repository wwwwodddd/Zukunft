#include <bits/stdc++.h>
using namespace std;
int p = 10007;
int pw(int x, int y) {
	x %= p;
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int main() {
	int a, b, k, n, m;
	scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
	int re = 1;
	for (int i = 0; i < m; i++) {
		re = re * (k - i) % p * pw(i + 1, p - 2) % p;
	}
	printf("%d\n", re * pw(a, n) % p * pw(b, m) % p);
	return 0;
}