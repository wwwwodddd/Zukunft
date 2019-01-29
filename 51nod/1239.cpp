#include <bits/stdc++.h>
using namespace std;
const int M = 5e6, mod = 1e9 + 7;
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
			f[i] = f[i / v[i]] * v[i];
		} else {
			f[i] = f[i / v[i]] * (v[i] - 1);
		}
	}
	for (int i = 1; i <= M; i++) {
		s[i] = (s[i - 1] + f[i]) % mod;
	}
}
map<long long, long long> g;
long long phisum(long long n) {
	if (n <= M) {
		return s[n];
	}
	if (g.find(n) != g.end()) {
		return g[n];
	}
	long long &re = g[n];
	re = n % mod;
	re = re * (re + 1) / 2 % mod;
	for (long long i = 2, l; i <= n; i = l + 1) {
		l = n / (n / i);
		re = (re - (l - i + 1) * phisum(n / i)) % mod;
	}
	if (re < 0) {
		re += mod;
	}
	return re;
}
int main() {
	init();
	cin >> n;
	cout << phisum(n) << endl;
}