#include <bits/stdc++.h>
using namespace std;
const int M = 1e7, mod = 1e9 + 7;
long long n;
int v[M + 20];
int f[M + 20];
long long s[M + 20];
void init() {
	for (int i = 2; i <= M; i++) {
		if (v[i] == 0) {
			for (int j = i; j <= M; j += i) {
				v[j] = i;
			}
		}
	}
	f[1] = 1;
	for (int i = 2; i <= M; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = 0;
		} else {
			f[i] = -f[i / v[i]];
		}
	}
	for (int i = 1; i <= M; i++) {
		s[i] = (s[i - 1] + f[i] + mod) % mod;
	}
}
map<long long, long long> g;
long long musum(long long n) {
	if (n <= M) {
		return s[n];
	}
	if (g.find(n) != g.end()) {
		return g[n];
	}
	long long &re = g[n];
	re = 1;
	for (long long i = 2, l; i <= n; i = l + 1) {
		l = n / (n / i);
		re = (re - (l - i + 1) * musum(n / i)) % mod;
	}
	if (re < 0) {
		re += mod;
	}
	return re;
}
long long F(long long n) {
	long long re = 0;
	for (long long i = 1, l; i <= n; i = l + 1) {
		l = n / (n / i);
		long long t = (n / i) % mod;
		re = (re + t * t % mod * (musum(l) - musum(i - 1) + mod)) % mod;
	}
	return re;
}
int main() {
	init();
	n = 1e11;
	long long ans = 0;
	for (long long i = n / 2; i > 0; i /= 2) {
		ans = (ans + F(i) - 1) % mod;
//		cerr << F(i) << endl;
	}
	if (ans & 1) {
		ans += mod;
	}
	ans /= 2;
	cout << ans << endl;
}