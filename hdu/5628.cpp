#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int t, n, m;
int f[100020];
int maxfactor[100020];
int maxfacpow[100020];
int maxfacnum[100020];
long long g[100020];
long long inv[100020];
int main() {
	inv[1] = 1;
	for (int i = 2; i < 100010; i++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	for (int i = 2; i < 100010; i++) {
		if (maxfactor[i] > 0) {
			continue;
		}
		for (int j = i; j < 100010; j += i) {
			maxfactor[j] = i;
		}
	}
	for (int i = 2; i < 100010; i++) {
		if (maxfactor[i] == maxfactor[i / maxfactor[i]]) {
			maxfacpow[i] = maxfacpow[i / maxfactor[i]] * maxfactor[i];
			maxfacnum[i] = maxfacnum[i / maxfactor[i]] + 1;
		} else {
			maxfacpow[i] = maxfactor[i];
			maxfacnum[i] = 1;
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &f[i]);
		}
		long long c[20] = {1};
		for (int i = 0; i < 20; i++) {
			c[i + 1] = c[i] * (m + i) % mod * inv[i + 1] % mod;
		}
		g[1] = 1;
		for (int i = 2; i <= n; i++) {
			g[i] = g[i / maxfacpow[i]] * c[maxfacnum[i]] % mod;
		}
		for (int i = n; i > 0; i--) {
			for (int j = 2; i * j <= n; j++) {
				f[i * j] = (f[i * j] + f[i] * g[j]) % mod;
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d%c", f[i], i == n ? '\n' : ' ');
		}
	}
	return 0;
}