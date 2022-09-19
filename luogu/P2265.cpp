#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int  pw(long long x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % p;
		}
		x = x * x % p;
	}
	return re;
}
int n, m;
int main() {
	cin >> n >> m;
	long long re = 1;
	for (int i = 0; i < m; i++) {
		re = re * (n + m - i) % p * pw(i + 1, p - 2) % p;
	}
	printf("%lld\n", re);
	return 0;
}