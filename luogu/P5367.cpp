#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, x;
int c[1000020];
void change(int x, int y) {
	for (int i = x; i <= n; i += i & -i) {
		c[i] += y;
	}
}
int query(int x) {
	int re = 0;
	for (int i = x; i > 0; i -= i & -i) {
		re += c[i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	long long re = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		change(x, 1);
		re = (re * (n - i) + x - query(x)) % mod;
	}
	printf("%lld\n", (re + 1) % mod);
	return 0;
}