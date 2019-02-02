#include <bits/stdc++.h>
using namespace std;
int n, m, l, p = 1000000007;
int f[5020];
int s[5020];
int c[5020];
int v[26];
int z[5020];
int pw(int x, int y) {
	int re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main() {
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &s[i], &c[i]);
	}
	f[0] = 1;
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= s[j]) {
				f[i] = (f[i] + f[i - s[j]]) % p;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		z[c[i]] = (z[c[i]] + f[l - s[i]]) % p;
	}
	for (int i = 0; i < m; i++) {
		char ch;
		scanf(" %c", &ch);
		v[ch - 'A']++;
	}
	int ans = 1;
	for (int i = 0; i < 26; i++) {
		if (v[i] == 0) {
			continue;
		}
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp = (tmp + pw(z[j], v[i])) % p;
		}
		ans = (long long)ans * tmp % p;
	}
	printf("%d\n", ans);
	return 0;
}