#include <bits/stdc++.h>
using namespace std;
int v[50020];
int p[50020], pc;
int c[50020], cnt;
map<int, int> g;
long long ans;
long long mod = 1000000000;
int a[5200];
int b[5200];
long long comb[5200][5200];
long long pw[20][5200];
long long pw2[60000020];
long long power(long long x, long long y) {
	long long re = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) {
			re = re * x % mod;
		}
		x = x * x % mod;
	}
	return re;
}
void dfs(int x, long long y, long long z) {
	if (x == cnt) {
		if (z < 60000010) {
			ans = (ans + y * pw2[z]) % mod;
		} else {
			ans = (ans + y * power(2, z)) % mod;
		}
	} else {
		for (int i = 0; i <= b[x]; i++) {
			long long ny = y * comb[b[x]][i] % mod;
			long long nz = z * pw[a[x]][b[x] - i] % mod * pw[a[x] - 1][i] % mod;
			dfs(x + 1, i & 1 ? -ny : ny, nz);
		}
	}
}
int main() {
	int n = 50000;
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		p[pc++] = i;
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}
	for (int i = 0; i < pc; i++) {
		int t = n;
		while (t > 0) {
			t /= p[i];
			c[i]++;
		}
	}
	for (int i = 0; i < pc; i++) {
		g[c[i]]++;
	}
	for (pair<int, int> i: g) {
		a[cnt] = i.first;
		b[cnt] = i.second;
		cnt++;
	}
	for (int i = 0; i < 5100; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}
	}
	for (int i = 1; i < 20; i++) {
		pw[i][0] = 1;
		for (int j = 1; j < 5100; j++) {
			pw[i][j] = pw[i][j - 1] * i % mod;
		}
	}
	pw2[0] = 1;
	for (int i = 1; i < 60000010; i++) {
		pw2[i] = pw2[i - 1] * 2 % mod;
	}
	dfs(0, 1, 1);
	if (ans < 0) {
		ans += mod;
	}
	cout << ans << endl;
	return 0;
}