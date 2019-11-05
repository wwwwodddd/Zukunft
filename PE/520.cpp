#include <bits/stdc++.h>
using namespace std;
int p = 1000000123, m;
int a[13][13], b[13][13];
void mul(int a[13][13], int b[13][13], int c[13][13]) {
	int w[13][13] = {};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(c, w, sizeof w);
}

long long F1(long long n, int t) {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	m = t + 2;
	a[0][t - 5] = 1;
	for (int i = 0; i < t; i++) {
		b[i][i + 1] = t - i;
		b[i + 1][i] = i + 1;
	}
	b[m - 1][m - 1] = 1;
	b[1][m - 1] = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b, a);
		}
		mul(b, b, b);
	}
	return a[0][m - 1];
}

long long F2(long long n, int t) {
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	m = t + 2;
	n--;
	a[0][t - 4] = 1;
	for (int i = 0; i < t; i++) {
		b[i][i + 1] = t - i;
		b[i + 1][i] = i + 1;
	}
	b[m - 1][m - 1] = 1;
	b[1][m - 1] = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b, a);
		}
		mul(b, b, b);
	}
	return a[0][m - 1];
}

long long C(int n, int m) {
	long long re = 1;
	for (int i = 0; i < m; i++) {
		re = re * (n - i) / (i + 1);
	}
	return re;
}
long long Q(long long n) {
//	cerr << n << endl;
	long long ans = 0;
	for (int i = 5; i <= 10; i++) {
//		cerr << i << " --" << endl;
//		cerr << (F1(n, i)) * C(5, i - 5) % p << endl;
//		cerr << (F2(n, i)) * C(5, i - 5) % p << endl;
		ans += (F1(n, i) - F2(n, i) + p) * C(5, i - 5) % p;
	}
	return ans % p;
}
int main() {
	cerr << Q(100) << endl;
	cerr << Q(7) << endl;
	long long ans = 0;
	for (int i = 1; i < 40; i++) {
		ans = (ans + Q(1LL << i)) % p;
	}
	cerr << ans << endl;
}